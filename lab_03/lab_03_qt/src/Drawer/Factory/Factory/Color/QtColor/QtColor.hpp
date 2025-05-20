//
// Created by nuelex on 20/05/25.
//

#ifndef QTCOLOR_HPP
#define QTCOLOR_HPP
#include <memory>
#include <qcolor.h>

#include "../BaseColor.hpp"
#include "../../../../ColorParameters/BaseColorParameters.hpp"


class QtColor : public BaseColor
{
public:
    QtColor() = delete;
    explicit QtColor(const std::shared_ptr<BaseColorParameters> &cp) : BaseColor(cp), \
                                                        _color(cp->getR(), cp->getG(), cp->getB()) {}
    ~QtColor() override = default;

    [[nodiscard]] const QColor& getColor() const { return _color; }

private:
    QColor _color;
};



#endif //QTCOLOR_HPP
