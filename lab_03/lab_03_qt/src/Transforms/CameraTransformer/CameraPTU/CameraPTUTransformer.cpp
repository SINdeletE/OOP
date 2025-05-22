//
// Created by nuelex on 21/05/25.
//

#include "CameraPTUTransformer.hpp"

#include "../../../Exceptions/transform/TransformerException.hpp"
#include "../../../Exceptions/transform/VecException.hpp"

CameraPTUTransformer::CameraPTUTransformer(const std::shared_ptr<Camera> &camera) : BaseCameraTransformer(camera)
{
    auto cameraPtr = std::dynamic_pointer_cast<BaseCameraPTU>(camera);
    if (cameraPtr == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformer_invalid_camera(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _camera = cameraPtr;
}

Point CameraPTUTransformer::transform(const Point &other) const
{
    const Vec pos{_camera->getPosition()};
    const Vec target{_camera->getTarget()};
    const Vec up{_camera->getUp()};
    const Vec other_vec{other};

    Vec F = target - pos;
    try
    {
        F.normalize();
    }
    catch (ErrorVec_invalid_vec &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformer_invalid_camera_parameters(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    Vec R{F.vecMulConst(up)};
    try
    {
        R.normalize();
    }
    catch (ErrorVec_invalid_vec &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformer_invalid_camera_parameters(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    const Vec q{R.vecMulConst(F)}; // уже normalize
    const Vec p{other_vec - pos};

    return toPerspective({p * R, p * q, p * (-F)});
}

Point CameraPTUTransformer::toPerspective(const Point& point)
{
    return {point.GetX() / point.GetZ(), point.GetY() / point.GetZ(), point.GetZ()};
}



