//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPDUDIRECTOR_HPP
#define CAMERAPDUDIRECTOR_HPP
#include "../BaseObjectDirector.hpp"
#include "../../Builders/CameraPTUBuilder/BaseCameraPTUBuilder.hpp"


class CameraPTUDirector : public BaseObjectDirector
{
public:
    explicit CameraPTUDirector(const std::string &filename);
    ~CameraPTUDirector() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> create() override;

private:
    std::shared_ptr<BaseCameraPTUBuilder> _builder;
};



#endif //CAMERAPDUDIRECTOR_HPP
