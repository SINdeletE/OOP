//
// Created by nuelex on 20/05/25.
//

#ifndef QTPEN_HPP
#define QTPEN_HPP
#include <qpen.h>


#include "../BasePen.hpp"
#include "../../Color/QtColor/QtColor.hpp"

class QtPen : public BasePen
{
public:
    QtPen() = delete;
    explicit QtPen(const std::shared_ptr<BaseColor> &color);
    ~QtPen() override = default;

    [[nodiscard]] std::shared_ptr<QPen> getPen() const { return _pen; }
private:
    std::shared_ptr<QPen> _pen;
};



#endif //QTPEN_HPP
