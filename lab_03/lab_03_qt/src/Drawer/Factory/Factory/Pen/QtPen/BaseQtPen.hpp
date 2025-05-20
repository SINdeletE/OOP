//
// Created by nuelex on 20/05/25.
//

#ifndef BASEQTPEN_HPP
#define BASEQTPEN_HPP
#include "QtPen.hpp"
#include "../BasePen.hpp"


class BaseQtPen : public BasePen
{
public:
    BaseQtPen() = delete;
    explicit BaseQtPen(const std::shared_ptr<BaseColor> &color) : BasePen(color) {}
    ~BaseQtPen() override = default;

    [[nodiscard]] virtual std::shared_ptr<QPen> getPen() const = 0;
};



#endif //BASEQTPEN_HPP
