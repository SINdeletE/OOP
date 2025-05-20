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
    explicit BaseColor(const BaseColorParameters& color_param) {}
    ~BaseColor() = default;
};



#endif //BASECOLOR_HPP
