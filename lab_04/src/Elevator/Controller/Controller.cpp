//
// Created by nuelex on 28/05/25.
//

#include "Controller.hpp"

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
    }
    else if (direction == Direction::DOWN)
    {
        const auto button = std::make_shared<ElevatorButton>();

        button->setFloor(_elevatorButtons_DOWN.size() + 1);
        button->setDirection(direction);
        _elevatorButtons_DOWN.push_back(button);
    }
}

void Controller::addInsideButton()
{
    const auto button = std::make_shared<ElevatorButton>();

    button->setFloor(_elevatorButtons_DOWN.size());
    button->setDirection(NONE);
    _insideButtons.push_back(button);
}

void Controller::elevatorButtonClicked(const int floor) const
{
    _insideButtons[floor - 1]->slotPressed();
}
