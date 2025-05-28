//
// Created by nuelex on 28/05/25.
//

#include "Elevator.hpp"

Elevator::Elevator(QObject* parent) : QObject(parent)
{
    connect(&_door, &ElevatorDoor::signalDoorClosed,
            this, &Elevator::endTarget);
    connect(&_movetime, &QTimer::timeout,
            this, &Elevator::onTarget);
}

void Elevator::onTarget()
{
    if (_state == MOVING)
    {
        _state = WAITING;
        _door.slotOpening();
        emit signalOnTarget();
    }
}

void Elevator::endTarget()
{
    if (_state == WAITING)
    {
        _state = STOPPED;
        emit signalEndTarget();
    }
}




