//
// Created by nuelex on 19/05/25.
//

#ifndef BASECOLOR_HPP
#define BASECOLOR_HPP
#include "../../../ColorParameters/BaseColorParameters.hpp"


class BaseColor
{
public:
    BaseColor() = delete;
    explicit BaseColor(const std::shared_ptr<BaseColorParameters> &color_parameters) {}
    virtual ~BaseColor() = default;
};



#endif //BASECOLOR_HPP
