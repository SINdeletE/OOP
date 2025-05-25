//
// Created by nuelex on 16/05/25.
//

#ifndef BASECAMERA_HPP
#define BASECAMERA_HPP
#include "BaseCameraPTUImpl.hpp"
#include "Camera.hpp"
#include "../BaseObject.hpp"
#include "../../Transforms/Vec.hpp"


class BaseCameraPTU : public Camera
{
protected:
    std::shared_ptr<BaseCameraPTUImpl> _cameraPTU;

public:
    BaseCameraPTU() = default;
    ~BaseCameraPTU() override = default;

    bool VisibilityCheck() override { return false; }

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}

    void accept(const BaseDrawTemplateVisitor& visitor) override {}
    void accept(BaseTransformVisitor &visitor) override { visitor.visitCamera(*this); }
};



#endif //BASECAMERA_HPP
