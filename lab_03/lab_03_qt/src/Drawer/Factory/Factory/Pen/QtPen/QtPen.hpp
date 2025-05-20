//
// Created by nuelex on 20/05/25.
//

#ifndef QTPEN_HPP
#define QTPEN_HPP
#include <qpen.h>


#include "BaseQtPen.hpp"
#include "../BasePen.hpp"
#include "../../Color/QtColor/QtColor.hpp"

class QtPen : public BaseQtPen
{
public:
    QtPen() = delete;
    explicit QtPen(const std::shared_ptr<BaseColor> &color);
    ~QtPen() override = default;

    [[nodiscard]] std::shared_ptr<QPen> getPen() const override { return _pen; }
private:
    std::shared_ptr<QPen> _pen;
};



#endif //QTPEN_HPP
