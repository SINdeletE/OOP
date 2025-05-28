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

private:
    ControllerState _state{ABLE};

    std::vector<ElevatorButton> _elevatorButtons;
    std::vector<ElevatorButton> _floorButtons;
};



#endif //CONTROLLER_HPP
