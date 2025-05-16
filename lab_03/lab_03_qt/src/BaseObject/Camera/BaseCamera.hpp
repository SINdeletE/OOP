//
// Created by nuelex on 16/05/25.
//

#ifndef BASECAMERA_HPP
#define BASECAMERA_HPP
#include "../BaseObject.hpp"


class BaseCamera : public BaseObject
{
public:
    BaseCamera() = default;
    ~BaseCamera() override = default;

    bool VisibilityCheck() override { return false; }
};



#endif //BASECAMERA_HPP
