//
// Created by nuelex on 11/05/25.
//

#ifndef CAMERAACTIONMOVE_HPP
#define CAMERAACTIONMOVE_HPP
#include "../CameraAction.hpp"


class CameraActionMove : public CameraAction
{
public:
    CameraActionMove() = default;
    CameraActionMove(const CameraActionMove& other) : _camera(other._camera), _transform(other._transform) {}
    ~CameraActionMove() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override;

    void request() const override;

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Mover> _transform;
};



#endif //CAMERAACTIONMOVE_HPP
