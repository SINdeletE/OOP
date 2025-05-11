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
    ~CameraActionRotate() override = default;

    void request() const override {}
};



#endif //CAMERAACTIONROTATE_HPP
