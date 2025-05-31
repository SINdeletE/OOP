//
// Created by nuelex on 28/05/25.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <deque>
#include <qobject.h>

#include "../../consts.h"
#include "../buttons/ElevatorButton.hpp"

enum ControllerState
{
    ABLE,
    REQUESTING,
    CONTROLLING,
    UNABLETOCONTROL
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
    // GUI
    void floorButtonClicked(int floor, Direction direction) const;
    void elevatorButtonClicked(int floor) const;
    // GUI








    void targetRequest(int floor, Direction direction);
    void floorControl();

    void slotLock();
    void slotUnlock();






signals:
    void signalControllerStart(Direction direction);
    void signalControllerFinish();
    void signalReopen();

private:
    ControllerState _state{ABLE};

    Direction _currentDirection{NONE};
    std::deque<std::pair<int, Direction>> _targets{};
    int _currentFloor{1};

    std::vector<std::shared_ptr<ElevatorButton>> _elevatorButtons_UP;
    std::vector<std::shared_ptr<ElevatorButton>> _elevatorButtons_DOWN;
    std::vector<std::shared_ptr<ElevatorButton>> _insideButtons;

    static Direction diffToDirection(int diff);

    bool targetExists(int floor);
    void sameTargetProcessing(int floor, Direction direction);
    void parse(std::deque<std::pair<int, Direction>>::iterator &codirect_iter, \
               std::deque<std::pair<int, Direction>>::iterator &diffdirect_iter);
    Direction getNewDirection();
    bool isNeedToReopen(int floor, Direction direction);
};



#endif //CONTROLLER_HPP
