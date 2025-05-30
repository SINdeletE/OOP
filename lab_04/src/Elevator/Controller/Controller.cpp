//
// Created by nuelex on 28/05/25.
//

#include "Controller.hpp"

#include <iostream>

void Controller::floorButtonClicked(const int floor, const Direction direction) const
{
    if (direction == Direction::UP)
    {
        _elevatorButtons_UP[floor - 1]->slotPressed();
    }
    else if (direction == Direction::DOWN)
    {
        _elevatorButtons_DOWN[floor - 1]->slotPressed();
    }
}

Controller::Controller()
{
    for (int i = 0; i < FLOORS; ++i)
    {
        addElevatorButton(UP);
        addElevatorButton(DOWN);
        addInsideButton();
    }
}

void Controller::addElevatorButton(const Direction direction)
{
    if (direction == Direction::UP)
    {
        const auto button = std::make_shared<ElevatorButton>();

        button->setFloor(_elevatorButtons_UP.size() + 1);
        button->setDirection(direction);
        _elevatorButtons_UP.push_back(button);

        connect(button.get(), &ElevatorButton::signalPressed, \
                this, &Controller::targetRequest);
    }
    else if (direction == Direction::DOWN)
    {
        const auto button = std::make_shared<ElevatorButton>();

        button->setFloor(_elevatorButtons_DOWN.size() + 1);
        button->setDirection(direction);
        _elevatorButtons_DOWN.push_back(button);

        connect(button.get(), &ElevatorButton::signalPressed, \
                this, &Controller::targetRequest);
    }
}

void Controller::addInsideButton()
{
    const auto button = std::make_shared<ElevatorButton>();

    button->setFloor(_elevatorButtons_DOWN.size());
    button->setDirection(NONE);
    _insideButtons.push_back(button);

    connect(button.get(), &ElevatorButton::signalPressed, \
                this, &Controller::targetRequest);
}

void Controller::elevatorButtonClicked(const int floor) const
{
    // GUI
    _insideButtons[floor - 1]->slotPressed();
}

void Controller::targetRequest(const int floor, const Direction direction)
{
    if (_state == ABLE || _state == UNABLETOCONTROL || _state == REQUESTING || _state == CONTROLLING)
    {
        bool flag = true;
        if (_state == UNABLETOCONTROL)
            flag = false;

        _state = REQUESTING;

        if (_targets.empty())
        {
            if (! (! flag && floor == _currentFloor))
            {
                _targets.emplace_front(floor, direction);
                _currentDirection = diffToDirection(floor - _currentFloor);
            }

            if (flag)
                emit signalControllerStart(_currentDirection);
            else if (floor == _currentFloor)
                emit signalReopen();
        }
        else
        {
            this->sameTargetProcessing(floor, direction);

            if (! flag && floor == _currentFloor)
                emit signalReopen();
            else
                _targets.emplace_front(floor, direction);
        }
    }
}

void Controller::floorControl()
{
    if (_state == ABLE || _state == REQUESTING || _state == CONTROLLING)
    {
        _state = CONTROLLING;

        auto codirect_iter = _targets.end(); // Поиск кнопки НЕпротивоположного направления того же этажа
        auto diffdirect_iter = _targets.end(); // Поиск кнопки противоположного направления того же этажа
        this->parse(codirect_iter, diffdirect_iter);

        // Обработка НЕпротивоположного направления с тем же этажом
        if (codirect_iter != _targets.end())
        {
            _targets.erase(codirect_iter);

            emit signalControllerFinish();
        }
        else
        {
            // Обработка этажа противоположного направления
            if (diffdirect_iter != _targets.end() && diffdirect_iter->first == _currentFloor)
            {
                _targets.erase(diffdirect_iter);

                emit signalControllerFinish();
            }
            else
            {
                if (_currentFloor + _currentDirection > 0 && \
                    _currentFloor + _currentDirection <= FLOORS) _currentFloor += _currentDirection;
                std::cout << "Лифт на этаже " << _currentFloor << std::endl;
            }
        }
    }
}

Direction Controller::diffToDirection(const int diff)
{
    if (diff > 0)
    {
        return UP;
    }

    return DOWN;
}

void Controller::slotLock()
{
    _state = UNABLETOCONTROL;
}

void Controller::slotUnlock()
{
    if (_state == UNABLETOCONTROL || _state == REQUESTING)
    {
        _state = ABLE;

        Direction direction = NONE;

        if (! _targets.empty())
        {
            direction = getNewDirection();
        }

        _currentDirection = direction;
        emit signalControllerStart(direction);
    }
}

bool Controller::targetExists(const int floor)
{
    bool flag = false;
    for (auto iter = _targets.begin(); ! flag && iter != _targets.end(); ++iter)
        if (iter->first == floor)
            flag = true;

    return flag;
}

void Controller::sameTargetProcessing(const int floor, const Direction direction)
{
    bool flag = false;
    for (auto iter = _targets.begin(); ! flag && iter != _targets.end(); ++iter)
        if (iter->first == floor)
        {
            flag = true;

            if (iter->second != direction)
                iter->second = NONE;
        }
}

void Controller::parse(std::deque<std::pair<int, Direction>>::iterator& codirect_iter,
                       std::deque<std::pair<int, Direction>>::iterator& diffdirect_iter)
{
    auto codirect_tmp_iter = _targets.end();
    codirect_iter = _targets.end(); // Поиск кнопки НЕпротивоположного направления того же этажа
    diffdirect_iter = _targets.end(); // Поиск кнопки противоположного направления того же этажа
    for (auto iter = _targets.begin(); iter != _targets.end(); ++iter)
    {
        // Находим хотя бы какой-то сигнал НЕпротивоположного направления
        if (iter->second != -_currentDirection)
        {
            codirect_tmp_iter = iter;
        }

        if (iter->first == _currentFloor && iter->second != -_currentDirection)
            codirect_iter = iter;
        else if (iter->first == _currentFloor && iter->second == -_currentDirection)
            diffdirect_iter = iter;
    }


    // Максимальный этаж НЕпротивополодного направления
    auto max_codirect_iter = codirect_tmp_iter;
    for (auto iter = _targets.begin(); iter != _targets.end(); ++iter)
    {
        // Поиск максимально удалённого этажа НЕпротивоположного направления
        if (codirect_tmp_iter != _targets.end() && \
            _currentDirection * iter->first > _currentDirection * codirect_tmp_iter->first && \
            iter->second != -_currentDirection)
        {
            max_codirect_iter = iter;
        }

        // Поиск максимально удалённого этажа противоположного направления
        if (diffdirect_iter != _targets.end() && \
            _currentDirection * iter->first > _currentDirection * diffdirect_iter->first && \
            iter->second == -_currentDirection)
        {
            diffdirect_iter = iter;
        }
    }

    // Если существует этаж того же направления, больший этажа противоположного направления, то
    // Обработка этажа с противоположным направлением не имеет смысла
    if (max_codirect_iter != _targets.end() && diffdirect_iter != _targets.end() && \
        _currentDirection * max_codirect_iter->first > _currentDirection * diffdirect_iter->first)
        diffdirect_iter = _targets.end();
}

Direction Controller::getNewDirection()
{
    Direction direction = NONE;

    if (_targets.empty())
    {
        direction = NONE;
    }
    else
    {
        bool flag = true;
        for (auto iter = _targets.begin(); flag && iter != _targets.end(); ++iter)
            if (_currentDirection * (iter->first - _currentFloor) >= 0)
                flag = false;

        if (flag)
        {
            if (_currentDirection == UP)
                direction = DOWN;
            else if (_currentDirection == DOWN)
                direction = UP;
        }
        else
            direction = _currentDirection;
    }

    return direction;
}


