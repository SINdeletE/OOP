//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPDUDIRECTOR_HPP
#define CAMERAPDUDIRECTOR_HPP
#include "../BaseObjectDirector.hpp"


class CameraPTUDirector : public BaseObjectDirector
{
public:
    explicit CameraPTUDirector(const std::string &filename);
    ~CameraPTUDirector() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> create() override { return nullptr; };

private:

};



#endif //CAMERAPDUDIRECTOR_HPP
