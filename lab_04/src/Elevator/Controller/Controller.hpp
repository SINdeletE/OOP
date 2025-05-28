//
// Created by nuelex on 28/05/25.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <qobject.h>

#include "../../consts.h"
#include "../buttons/ElevatorButton.hpp"

enum ControllerState
{
    ABLE,
    UNABLE
};

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller() override = default;

    void addElevatorButton(Direction direction);
    void addInsideButton();

public slots:
    void floorButtonClicked(int floor, Direction direction) const;
    void elevatorButtonClicked(int floor) const;

private:
    ControllerState _state{ABLE};

    std::vector<std::shared_ptr<ElevatorButton>> _elevatorButtons_UP;
    std::vector<std::shared_ptr<ElevatorButton>> _elevatorButtons_DOWN;
    std::vector<std::shared_ptr<ElevatorButton>> _insideButtons;
};



#endif //CONTROLLER_HPP
