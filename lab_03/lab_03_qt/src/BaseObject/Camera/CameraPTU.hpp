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
    friend class CameraPTUTransformer;
    friend class CameraPTUBuilder;

protected:
    CameraPTUImpl _cameraPTU;

public:
    CameraPTU() : _cameraPTU() {}
    ~CameraPTU() override = default;

    bool VisibilityCheck() override { return false; }
    bool CompositeCheck() override { return false; }

    void transform(const Mover &mover) override { _cameraPTU.transform(mover); }
    void transform(const Rotater &rotater) override { _cameraPTU.transform(rotater); }

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visitCamera(*this); }
};



#endif //CAMERA_HPP
