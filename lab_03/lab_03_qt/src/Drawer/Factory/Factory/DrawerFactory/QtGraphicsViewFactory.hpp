//
// Created by nuelex on 19/05/25.
//

#ifndef BASEDRAWERFACTORY_HPP
#define BASEDRAWERFACTORY_HPP
#include <qpen.h>

#include "../AbstractDrawerFactory.hpp"


class QtGraphicsViewFactory : public AbstractDrawerFactory
{
public:
    QtGraphicsViewFactory() = default;
    ~QtGraphicsViewFactory() override = default;

    std::shared_ptr<BasePen> createPen(const std::shared_ptr<BaseColor>& color) override;
    std::shared_ptr<BaseColor> createColor(const std::shared_ptr<BaseColorParameters>& color_param) override;
};



#endif //BASEDRAWERFACTORY_HPP
