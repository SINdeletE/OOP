//
// Created by nuelex on 28/05/25.
//

#ifndef ELEVATORSYSTEM_HPP
#define ELEVATORSYSTEM_HPP
#include <qobject.h>

#include "Elevator/Controller/Controller.hpp"
#include "Elevator/Elevator.hpp"

class ElevatorSystem : public QObject
{
    Q_OBJECT

public:
    ElevatorSystem();
    ~ElevatorSystem() override = default;

public slots:
    void handleFloorCall(int floor, Direction direction);
    void handleElevatorCall(int floor);

signals:
    void floorButtonClickedRequest(int floor, Direction direction);
    void elevatorButtonClickedRequest(int floor);

private:
    Elevator _elevators{};
    Controller _controller{};
};



#endif //ELEVATORSYSTEM_HPP
