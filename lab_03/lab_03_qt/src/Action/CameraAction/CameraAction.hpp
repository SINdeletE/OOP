//
// Created by nuelex on 11/05/25.
//

#ifndef CAMERAACTION_HPP
#define CAMERAACTION_HPP
#include "../BaseAction.hpp"


class CameraAction : public BaseAction
{
public:
    CameraAction() = default;
    ~CameraAction() override = default;

    void request() const override {}
};



#endif //CAMERAACTION_HPP
