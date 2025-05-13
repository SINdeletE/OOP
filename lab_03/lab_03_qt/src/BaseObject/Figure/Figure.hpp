//
// Created by nuelex on 09/05/25.
//

#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <memory>

#include "../BaseObject.hpp"
#include "../../Transforms/Transforms.hpp"

class Figure : public BaseObject
{
public:
    Figure() = default;
    ~Figure() override = default;

    bool CompositeCheck() override { return false; }
    bool VisibilityCheck() override { return true; }

    void move(const Mover &mover) override {}
    void rotate(const Rotater &rotater) override {}
    void scale(const Scaler &scaler) override {}

    BaseObject::iterator begin() override { return BaseObject::iterator(nullptr); }
    BaseObject::iterator end() override { return BaseObject::iterator(nullptr); }
};



#endif //FIGURE_HPP
