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
    void setDirection(const Direction direction) { _direction = direction; }

public slots:
    void slotPressed();

private slots:
    void slotReleased();

signals:
    void signalPressed(int &floor, Direction &direction);
    void signalReleased();

private:
    ButtonState _state{RELEASED};
    Direction _direction{NONE};

    int _floor;

    void buttonPrint();
};



#endif //ELEVATORBUTTON_HPP
