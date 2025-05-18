//
// Created by nuelex on 11/05/25.
//

#ifndef CAMERAACTIONROTATE_HPP
#define CAMERAACTIONROTATE_HPP
#include "../CameraAction.hpp"


class CameraActionRotate : public CameraAction
{
public:
    CameraActionRotate() = default;
    CameraActionRotate(const CameraActionRotate& other) : _camera(other._camera), _transform(other._transform) {}
    ~CameraActionRotate() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override;

    void request() const override;

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<Rotater> _transform;
};



#endif //CAMERAACTIONROTATE_HPP
