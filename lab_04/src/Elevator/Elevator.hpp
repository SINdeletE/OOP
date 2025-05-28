//
// Created by nuelex on 28/05/25.
//

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include <qobject.h>

#include "door/ElevatorDoor.hpp"

enum ElevatorState
{
    STOPPED,
    MOVING,
    TARGETING
};

class Elevator : public QObject
{
    Q_OBJECT

public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() override = default;

private:
    ElevatorState state{STOPPED};
    ElevatorDoor _door;

    int _currentFloor{0};
    int _targetFloor{0};

    void setTargetFloor(const int floor) { _targetFloor = floor; }
    void setcurrentFloor(const int floor) { _currentFloor = floor; }
};



#endif //ELEVATOR_HPP
