//
// Created by nuelex on 16/05/25.
//

#ifndef BASECAMERAPTUBUILDER_HPP
#define BASECAMERAPTUBUILDER_HPP
#include <memory>
#include <string>

#include "../../../BaseObject/Camera/CameraPTU.hpp"


class BaseCameraPTUBuilder
{
public:
    BaseCameraPTUBuilder() = delete;
    explicit BaseCameraPTUBuilder(const std::string &filename) {}
    virtual ~BaseCameraPTUBuilder() = default;

    virtual bool isBuilded() { return false; }
    virtual void reset() {}

    [[nodiscard]] virtual bool buildPosition() = 0;
    [[nodiscard]] virtual bool buildTarget() = 0;
    [[nodiscard]] virtual bool buildUp() = 0;
    [[nodiscard]] virtual std::shared_ptr<BaseCameraPTU> getCameraPTU() const = 0;
};



#endif //BASECAMERAPTUBUILDER_HPP
