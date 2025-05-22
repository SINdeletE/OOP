//
// Created by nuelex on 18/05/25.
//

#ifndef QTDRAWER_HPP
#define QTDRAWER_HPP
#include <QGraphicsScene>

#include "BaseDrawer.hpp"
#include "../Factory/Factory/Pen/BasePen.hpp"
#include "../Factory/Factory/Pen/QtPen/QtPen.hpp"
#include "../Graphics/BaseGraphics.hpp"
#include "../Graphics/Qt/QtGraphicsScene.hpp"


class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;
    ~QtDrawer() override = default;

    void setScene(const std::shared_ptr<BaseGraphics> &graphics) override;
    void setPen(const std::shared_ptr<BasePen> &pen) override;
    [[nodiscard]] QGraphicsScene *getScene() const { return _scene->getScene(); }

    void drawLine(const Point& start, const Point& end) override { _scene->getScene()->addLine(start.GetX(), \
                                                                                                start.GetY(), end.GetX(), end.GetY(), *_pen->getPen()); }
    void clear() override { _scene->getScene()->clear(); }

private:
    std::shared_ptr<QtGraphicsScene> _scene;
    std::shared_ptr<QtPen> _pen;
};



#endif //QTDRAWER_HPP
