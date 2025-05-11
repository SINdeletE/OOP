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
    ~CameraActionMove() override = default;

    void request() const override {}
};



#endif //CAMERAACTIONMOVE_HPP
