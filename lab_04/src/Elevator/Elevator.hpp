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
    MOVING
};

class Elevator : public QObject
{
    Q_OBJECT

public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() override = default;

    [[nodiscard]] Direction getDirection() const { return _direction; }
    void setDirection(Direction direction) { _direction = direction; }

public slots:
    void slotStart(Direction direction);
    void onTarget();

private slots:
    void onFloor();
    void endTarget();

signals:
    void signalStart();

    void signalOnTarget();
    void signalOnFloor();
    void signalEndTarget();

private:
    ElevatorState _state{STOPPED};
    Direction _direction{NONE};
    ElevatorDoor _door{};

    QTimer _movetime;
};



#endif //ELEVATOR_HPP
