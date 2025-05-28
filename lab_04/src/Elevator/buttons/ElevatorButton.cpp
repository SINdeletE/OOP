//
// Created by nuelex on 28/05/25.
//

#include "ElevatorButton.hpp"

#include <QPushButton>


ElevatorButton::ElevatorButton(QWidget* parent) : QPushButton(parent), _floor(1)
{
    connect(this, &ElevatorButton::pressed,
        this, &ElevatorButton::slotPressed);

    connect(this, &ElevatorButton::released,
        this, &ElevatorButton::slotReleased);
}

void ElevatorButton::slotPressed()
{
    if (_state == RELEASED)
    {
        _state = PRESSED;
        emit signalPressed(_floor, _direction);
    }
}

void ElevatorButton::slotReleased()
{
    if (_state == PRESSED)
    {
        _state = RELEASED;
        emit signalReleased();
    }
}


