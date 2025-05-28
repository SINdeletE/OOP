//
// Created by nuelex on 28/05/25.
//

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include <qobject.h>

#include "../consts.h"
#include "door/ElevatorDoor.hpp"

enum ElevatorState
{
    WAITING,
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

    int getCurrentFloor() const { return _currentFloor; }
    int getTargetFloor() const { return _targetFloor; }

private slots:
    void onTarget();
    void onFloor();
    void endTarget();

signals:
    void signalOnTarget();
    void signalOnFloor(int floor);
    void signalEndTarget();

private:
    ElevatorState _state{STOPPED};
    Direction _direction{NONE};
    ElevatorDoor _door{};

    int _currentFloor{0};

    int _targetFloor{0};
    bool _isTargeting{false};

    QTimer _movetime;

    void setTargetFloor(const int floor) { _targetFloor = floor; }
    void setcurrentFloor(const int floor) { _currentFloor = floor; }
};



#endif //ELEVATOR_HPP
