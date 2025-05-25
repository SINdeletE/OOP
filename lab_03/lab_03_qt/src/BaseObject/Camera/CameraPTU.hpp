//
// Created by nuelex on 10/05/25.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "BaseCameraPTU.hpp"
#include "CameraPTUImpl.hpp"
#include "../BaseObject.hpp"
#include "../../Transforms/Vec.hpp"

class CameraPTUTransformer;
class CameraPTUBuilder;

class CameraPTU : public BaseCameraPTU
{
    friend class MoveObjectVisitor;
    friend class RotateObjectVisitor;
    friend class ScaleObjectVisitor;

    friend class CameraPTUTransformer;
    friend class CameraPTUBuilder;

public:
    CameraPTU() = default;
    explicit CameraPTU(const std::shared_ptr<BaseCameraPTUImpl> &cameraPTU) { _cameraPTU = cameraPTU; }
    ~CameraPTU() override = default;

    bool VisibilityCheck() override { return false; }
    bool CompositeCheck() override { return false; }

    void transform(const Mover &mover) override { _cameraPTU->transform(mover); }
    void transform(const Rotater &rotater) override { _cameraPTU->transform(rotater); }

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visit(*this); }
};



#endif //CAMERA_HPP
