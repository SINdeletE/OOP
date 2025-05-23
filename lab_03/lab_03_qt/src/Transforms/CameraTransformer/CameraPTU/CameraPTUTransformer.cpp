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
    Vec up{_camera->getUp()};
    const Vec other_vec{other};

    up.normalize();

    Vec Forward = pos - target;
    try
    {
        Forward.normalize();
    }
    catch (ErrorVec_invalid_vec &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformer_invalid_camera_parameters(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    Vec Right{up.vecMulConst(Forward)};
    try
    {
        Right.normalize();
    }
    catch (ErrorVec_invalid_vec &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformer_invalid_camera_parameters(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    const Vec Up{Forward.vecMulConst(Right)}; // уже normalize
    const double x_camera = (other_vec * Right) - (Right * pos);
    const double y_camera = (other_vec * Up) - (Up * pos);
    const double z_camera = (other_vec * Forward) - (Forward * pos);

    return {x_camera, y_camera, z_camera};
}

Point CameraPTUTransformer::toPerspective(const Point& point)
{
    return {point.GetX() / point.GetZ(), point.GetY() / point.GetZ(), point.GetZ()};
}



