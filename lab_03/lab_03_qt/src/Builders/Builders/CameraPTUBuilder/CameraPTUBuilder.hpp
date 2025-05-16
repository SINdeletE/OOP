//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPTUBUILDER_HPP
#define CAMERAPTUBUILDER_HPP
#include "BaseCameraPTUBuilder.hpp"
#include "../../Readers/PTUReader/BasePTUReader.hpp"


class CameraPTUBuilder : public BaseCameraPTUBuilder
{
public:
    CameraPTUBuilder() = delete;
    explicit CameraPTUBuilder(const std::string &filename);
    ~CameraPTUBuilder() override = default;

    [[nodiscard]] bool buildPosition();
    [[nodiscard]] bool buildTarget();
    [[nodiscard]] bool buildUp();
    [[nodiscard]] std::shared_ptr<BaseCamera> getCameraPTU() const;

private:
    Point _position;
    Point _target;
    Point _up;
    std::shared_ptr<CameraPTU> _camera;
    std::shared_ptr<BasePTUReader> _reader;
};



#endif //CAMERAPTUBUILDER_HPP
