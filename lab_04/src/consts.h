//
// Created by nuelex on 28/05/25.
//

#ifndef CONSTS_H
#define CONSTS_H

// Время: Двери
#define TIMER_DOOR_OPENING 2000
#define TIMER_DOOR_OPEN 3000
#define TIMER_DOOR_CLOSING 2000

// Время: Лифт
#define TIMER_ELEVATOR_FLOORS_PERIOD 2000

// Характеристики системы
#define FLOORS 5
#define ELEVATORS 1

//

enum Direction
{
    NONE = 0,
    UP = 1,
    DOWN = -1,
};

#endif //CONSTS_H
