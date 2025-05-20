//
// Created by nuelex on 20/05/25.
//

#ifndef QTCOLOR_HPP
#define QTCOLOR_HPP
#include <memory>
#include <qcolor.h>

#include "BaseQtColor.hpp"
#include "../BaseColor.hpp"
#include "../../../../ColorParameters/BaseColorParameters.hpp"


class QtColor : public BaseQtColor
{
public:
    QtColor() = delete;
    explicit QtColor(const std::shared_ptr<BaseColorParameters> &cp) : BaseQtColor(cp), \
                                                        _color(cp->getR(), cp->getG(), cp->getB()) {}
    ~QtColor() override = default;

    [[nodiscard]] const QColor& getColor() const override { return _color; }

private:
    QColor _color;
};



#endif //QTCOLOR_HPP
