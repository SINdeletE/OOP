//
// Created by nuelex on 28/05/25.
//

#include "ElevatorSystem.hpp"

ElevatorSystem::ElevatorSystem()
{
    connect(this, &ElevatorSystem::elevatorButtonClickedRequest,
            &_controller, &Controller::elevatorButtonClicked);
    connect(this, &ElevatorSystem::floorButtonClickedRequest,
            &_controller, &Controller::floorButtonClicked);
}

void ElevatorSystem::handleFloorCall(const int floor, const Direction direction)
{
    emit floorButtonClickedRequest(floor, direction);
}

void ElevatorSystem::handleElevatorCall(const int floor)
{
    emit elevatorButtonClickedRequest(floor);
}



