//
// Created by nuelex on 20/05/25.
//

#ifndef BASEQTCOLOR_HPP
#define BASEQTCOLOR_HPP
#include <memory>

#include "QtColor.hpp"
#include "../BaseColor.hpp"


class BaseQtColor : public BaseColor
{
public:
    BaseQtColor() = delete;
    explicit BaseQtColor(const std::shared_ptr<BaseColorParameters> &cp) : BaseColor(cp) {}
    ~BaseQtColor() override = default;

    [[nodiscard]] virtual const QColor& getColor() const = 0;
};



#endif //BASEQTCOLOR_HPP
