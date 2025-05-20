//
// Created by nuelex on 19/05/25.
//

#ifndef QTGRAPHICSSCENE_HPP
#define QTGRAPHICSSCENE_HPP
#include <QGraphicsScene>

#include "../BaseGraphics.hpp"

class QtDrawer;

class QtGraphicsScene : public BaseGraphics
{
    friend class QtDrawer;

public:
    QtGraphicsScene() = delete;
    QtGraphicsScene(QGraphicsScene *scene, QGraphicsView *gV);

    ~QtGraphicsScene() override = default;

protected:
    QGraphicsView *getView() const { return _view; }
    QGraphicsScene *getScene() const { return _scene; }

private:
    QGraphicsView *_view;
    QGraphicsScene *_scene;
};



#endif //QTGRAPHICSSCENE_HPP
