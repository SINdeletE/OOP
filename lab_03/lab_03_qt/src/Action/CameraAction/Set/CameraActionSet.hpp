//
// Created by nuelex on 11/05/25.
//

#ifndef CAMERAACTIONSET_HPP
#define CAMERAACTIONSET_HPP
#include "../CameraAction.hpp"


class CameraActionSet : public CameraAction
{
public:
    CameraActionSet() = default;
    ~CameraActionSet() override = default;

    void request() const override {}
};



#endif //CAMERAACTIONSET_HPP
