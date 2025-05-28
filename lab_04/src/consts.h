//
// Created by nuelex on 28/05/25.
//

#ifndef CONSTS_H
#define CONSTS_H

// Время: Двери
#define TIMER_DOOR_OPENING 500
#define TIMER_DOOR_OPEN 3000
#define TIMER_DOOR_CLOSING 500

// Время: Лифт
#define TIMER_ELEVATOR_FLOORS_PERIOD 1000

// Характеристики системы
#define FLOORS 5
#define ELEVATORS 2

//

enum Direction
{
    NONE = 0,
    UP,
    DOWN,
};

#endif //CONSTS_H
