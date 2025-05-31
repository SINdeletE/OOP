//
// Created by nuelex on 28/05/25.
//

#include "ElevatorDoor.hpp"

#include <iostream>

#include "../../consts.h"

ElevatorDoor::ElevatorDoor()
{
    connect(&_opening, &QTimer::timeout,
            this, &ElevatorDoor::slotOpen);

    connect(&_waiting, &QTimer::timeout,
            this, &ElevatorDoor::slotClosing);

    connect(&_closing, &QTimer::timeout,
        this, &ElevatorDoor::slotClose);
}

void ElevatorDoor::slotOpening()
{
    if (_state == CLOSE || _state == CLOSING)
    {
        int time = 0;
        if (_state == CLOSING)
        {
            time = _closing.remainingTime();
            _closing.stop();
        }

        _state = OPENING;
        std::cout << "ДВЕРИ: Открываются" << std::endl;
        _opening.start(TIMER_DOOR_OPENING - time);
    }
}

void ElevatorDoor::slotOpen()
{
    if (_state == OPENING)
    {
        _state = OPEN;
        std::cout << "ДВЕРИ: Открыты" << std::endl;
        _waiting.start(TIMER_DOOR_OPEN);
    }
}

void ElevatorDoor::slotClosing()
{
    if (_state == OPEN)
    {
        _state = CLOSING;
        std::cout << "ДВЕРИ: Закрываются" << std::endl;
        _closing.start(TIMER_DOOR_CLOSING);
    }
}

void ElevatorDoor::slotClose()
{
    if (_state == CLOSING)
    {
        _state = CLOSE;
        std::cout << "ДВЕРИ: Закрыты" << std::endl;

        emit signalDoorClosed();
    }
}

