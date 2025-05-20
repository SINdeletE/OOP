//
// Created by nuelex on 19/05/25.
//

#ifndef QTGRAPHICSSCENE_HPP
#define QTGRAPHICSSCENE_HPP
#include <QGraphicsScene>

#include "../BaseGraphics.hpp"


class QtGraphicsScene : public BaseGraphics
{
public:
    QtGraphicsScene() = delete;
    explicit QtGraphicsScene(const std::shared_ptr<QGraphicsScene> &scene, QGraphicsView *gV) : _view(gV), _scene(scene) {}

    ~QtGraphicsScene() override = default;

private:
    QGraphicsView *_view;
    std::shared_ptr<QGraphicsScene> _scene;
};



#endif //QTGRAPHICSSCENE_HPP
