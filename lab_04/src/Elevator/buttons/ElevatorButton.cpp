//
// Created by nuelex on 28/05/25.
//

#include "ElevatorButton.hpp"

#include <QPushButton>
#include <iostream>


ElevatorButton::ElevatorButton(QWidget* parent) : QPushButton(parent), _floor(1)
{
    connect(this, &ElevatorButton::signalPressed,
        this, &ElevatorButton::slotReleased);
}

void ElevatorButton::slotPressed()
{
    if (_state == RELEASED)
    {
        this->buttonPrint();
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

void ElevatorButton::buttonPrint()
{
    if (_direction == UP)
        std::cout << _floor << ' ' << "UP" << std::endl;
    else if (_direction == DOWN)
        std::cout << _floor << ' ' << "DOWN" << std::endl;
    else if (_direction == NONE)
        std::cout << _floor << ' ' << "-" << std::endl;
}

