//
// Created by nuelex on 19/05/25.
//

#ifndef ABSTRACTDRAWERFACTORY_HPP
#define ABSTRACTDRAWERFACTORY_HPP
#include <memory>

#include "Color/BaseColor.hpp"
#include "Pen/BasePen.hpp"


class AbstractDrawerFactory
{
public:
    AbstractDrawerFactory() = default;
    virtual ~AbstractDrawerFactory() = default;

    virtual std::shared_ptr<BasePen> createPen(const std::shared_ptr<BaseColor>& color) = 0;
    virtual std::shared_ptr<BaseColor> createColor(const std::shared_ptr<BaseColorParameters>& color_param) = 0;
};



#endif //ABSTRACTDRAWERFACTORY_HPP
