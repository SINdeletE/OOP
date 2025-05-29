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
    if (_state == ABLE || _state == LOCK)
    {
        _state = _state;

        if (this->targetExists(floor, direction))
        {
            this->sameTargetProcessing(floor, direction);
            return;
        }

        if (direction == NONE)
        {
            if (_targets.empty())
            {
                _targets.emplace_front(floor, direction);
                _currentDirection = diffToDirection(floor - _currentFloor);

                if (_state != LOCK) emit signalControllerStart(_currentDirection);
            }
            else if (! _targets.empty() && diffToDirection(floor - _currentFloor) == _currentDirection)
            {
                _targets.emplace_front(floor, direction);
            }
            else
            {
                auto iter = _targets.begin();

                while (iter != _targets.end() && iter->second == NONE) ++iter;
                _targets.insert(iter, {floor, direction});
            }
        }
        else if (_targets.empty())
        {
            _targets.emplace_back(floor, direction);
            _currentDirection = diffToDirection(floor - _currentFloor);

            if (_state != LOCK) emit signalControllerStart(_currentDirection);
        }
        else if (! _targets.empty() && diffToDirection(floor - _currentFloor) == _currentDirection && direction == _currentDirection)
        {
            _targets.emplace_front(floor, direction);
        }
        else
            _targets.emplace_back(floor, direction);


    }
}

void Controller::floorControl()
{
    if (_state == ABLE)
    {
        _state = ABLE;

        auto codirect_iter = _targets.end();
        auto diffdirect_iter = _targets.end();
        for (auto iter = _targets.begin(); iter != _targets.end(); ++iter)
            if (iter->first == _currentFloor && iter->second != -_currentDirection)
                codirect_iter = iter;
            else if (iter->first == _currentFloor && iter->second == -_currentDirection)
                diffdirect_iter = iter;

        for (auto iter = _targets.begin(); iter != _targets.end(); ++iter)
            if (_currentDirection * iter->first > _currentDirection * diffdirect_iter->first && \
                iter->second == -_currentDirection)
                diffdirect_iter = iter;

        if (codirect_iter != _targets.end())
        {
            _targets.erase(codirect_iter);

            emit signalControllerFinish();
        }
        else
        {
            if (diffdirect_iter != _targets.end() && diffdirect_iter->first == _currentFloor)
            {
                _targets.erase(diffdirect_iter);

                emit signalControllerFinish();
            }
            else
            {
                _currentFloor += _currentDirection;
                std::cout << "Лифт на этаже " << _currentFloor << std::endl;
            }
        }
    }
}

Direction Controller::diffToDirection(const int diff)
{
    if (diff >= 0)
    {
        return UP;
    }

    return DOWN;
}

void Controller::slotLock()
{
    _state = LOCK;
}

void Controller::slotUnlock()
{
    _state = ABLE;

    Direction direction = NONE;

    if (! _targets.empty())
    {
        direction = diffToDirection(_targets.front().first - _currentFloor);
    }

    _currentDirection = direction;
    emit signalControllerStart(direction);
}

bool Controller::targetExists(const int floor, const Direction direction)
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
        if (iter->first == floor && iter->second != direction)
        {
            iter->second = NONE;
            flag = true;
        }
}
