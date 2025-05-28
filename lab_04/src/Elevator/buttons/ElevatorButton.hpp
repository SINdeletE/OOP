//
// Created by nuelex on 28/05/25.
//

#ifndef ELEVATORBUTTON_HPP
#define ELEVATORBUTTON_HPP
#include <QPushButton>

#include "../../consts.h"

enum ButtonState
{
    PRESSED,
    RELEASED
};

class ElevatorButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ElevatorButton(QWidget *parent = nullptr);
    ~ElevatorButton() override = default;

    void setFloor(const int floor) { _floor = floor; }

public slots:
    void slotPressed();

private slots:
    void slotReleased();

signals:
    void signalPressed(int &floor, DirectionState &direction);
    void signalReleased();

private:
    ButtonState _state{RELEASED};
    DirectionState _direction{NONE};

    int _floor;
};



#endif //ELEVATORBUTTON_HPP
