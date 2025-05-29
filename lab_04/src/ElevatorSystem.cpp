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

    connect(&_controller, &Controller::signalControllerStart,
            &_elevator, &Elevator::slotStart);
    connect(&_controller, &Controller::signalControllerFinish,
            &_elevator, &Elevator::onTarget);
    connect(&_elevator, &Elevator::signalOnFloor,
            &_controller, &Controller::floorControl);
    connect(&_elevator, &Elevator::signalOnTarget,
            &_controller, &Controller::slotLock);
    connect(&_elevator, &Elevator::signalEndTarget,
            &_controller, &Controller::slotUnlock);
}

void ElevatorSystem::handleFloorCall(const int floor, const Direction direction)
{
    emit floorButtonClickedRequest(floor, direction);
}

void ElevatorSystem::handleElevatorCall(const int floor)
{
    emit elevatorButtonClickedRequest(floor);
}



