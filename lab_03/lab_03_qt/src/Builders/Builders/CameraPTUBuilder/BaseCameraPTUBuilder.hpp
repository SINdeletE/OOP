//
// Created by nuelex on 16/05/25.
//

#ifndef BASECAMERAPTUBUILDER_HPP
#define BASECAMERAPTUBUILDER_HPP
#include <memory>
#include <string>

#include "../../BaseBuilder.hpp"
#include "../../../BaseObject/Camera/CameraPTU.hpp"


class BaseCameraPTUBuilder : public BaseBuilder
{
public:
    BaseCameraPTUBuilder() = delete;
    explicit BaseCameraPTUBuilder(const std::string &filename) {}
    ~BaseCameraPTUBuilder() override = default;

    bool isBuilded() override { return false; }
    void reset() override {}

    [[nodiscard]] virtual bool buildPosition() = 0;
    [[nodiscard]] virtual bool buildTarget() = 0;
    [[nodiscard]] virtual bool buildUp() = 0;
    [[nodiscard]] virtual std::shared_ptr<BaseCamera> getCameraPTU() const = 0;
};



#endif //BASECAMERAPTUBUILDER_HPP
