//
// Created by nuelex on 19/05/25.
//

#ifndef BASEPEN_HPP
#define BASEPEN_HPP
#include <memory>
#include "../Color/BaseColor.hpp"

class BasePen
{
public:
    BasePen() = delete;
    explicit BasePen(const std::shared_ptr<BaseColor> &color) {}
    virtual ~BasePen() = default;
};



#endif //BASEPEN_HPP
