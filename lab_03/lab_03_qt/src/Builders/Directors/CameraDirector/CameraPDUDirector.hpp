//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPDUDIRECTOR_HPP
#define CAMERAPDUDIRECTOR_HPP
#include "../BaseObjectDirector.hpp"


class CameraPDUDirector : public BaseObjectDirector
{
public:
    explicit CameraPDUDirector(const std::string &filename);
    ~CameraPDUDirector() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> create() override;
};



#endif //CAMERAPDUDIRECTOR_HPP
