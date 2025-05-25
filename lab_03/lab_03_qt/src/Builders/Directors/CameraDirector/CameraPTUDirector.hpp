//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPDUDIRECTOR_HPP
#define CAMERAPDUDIRECTOR_HPP
#include "../../Builders/CameraPTUBuilder/BaseCameraPTUBuilder.hpp"
#include "BaseCameraPTUDirector.hpp"


class CameraPTUDirector : public BaseCameraPTUDirector
{
public:
    explicit CameraPTUDirector(const std::shared_ptr<BaseCameraPTUBuilder> &builder) : _builder(builder) {}
    ~CameraPTUDirector() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> create() override;

private:
    std::shared_ptr<BaseCameraPTUBuilder> _builder;
};



#endif //CAMERAPDUDIRECTOR_HPP
