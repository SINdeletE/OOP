//
// Created by nuelex on 28/05/25.
//

#include "Elevator.hpp"

#include <iostream>

Elevator::Elevator(QObject* parent) : QObject(parent)
{
    connect(&_door, &ElevatorDoor::signalDoorClosed,
            this, &Elevator::endTarget);
    connect(&_movetime, &QTimer::timeout,
            this, &Elevator::onFloor);
    connect(this, &Elevator::signalStart,
            this, &Elevator::onFloor);
    connect(this, &Elevator::signalOnTarget,
            &_door, &ElevatorDoor::slotOpening);

    std::cout << "Лифт на этаже 1" << std::endl;
}

void Elevator::onTarget()
{
    if (_state == MOVING)
    {
        _state = WAITING;
        _direction = NONE;

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

void Elevator::onFloor()
{
    if (_direction)
    {
        if (_state == STOPPED)
        {
            _state = MOVING;
        }
        else
        {
            emit signalOnFloor();
        }
        _movetime.start(TIMER_ELEVATOR_FLOORS_PERIOD);
    }
    // else
    //     _movetime.start(20);
}

void Elevator::slotStart(const Direction direction)
{
    _direction = direction;

    emit signalStart();
}



