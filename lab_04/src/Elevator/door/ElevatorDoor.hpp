//
// Created by nuelex on 28/05/25.
//

#ifndef ELEVATORDOOR_HPP
#define ELEVATORDOOR_HPP

#include <qobject.h>
#include <QTimer>

enum DoorState
{
    CLOSE,
    CLOSING,
    OPEN,
    OPENING,
};

class ElevatorDoor : public QObject
{
    Q_OBJECT

public:
    ElevatorDoor();
    ~ElevatorDoor() = default;

public slots:
    void slotOpening();

private slots:
    void slotOpen();
    void slotClosing();
    void slotClose();

signals:
    void signalDoorClosed();

private:
    DoorState _state{CLOSE};

    QTimer _opening;
    QTimer _waiting;
    QTimer _closing;
};



#endif //ELEVATORDOOR_HPP
