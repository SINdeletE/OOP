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
    explicit CameraPTUBuilder(const std::shared_ptr<BasePTUReader> &reader);
    ~CameraPTUBuilder() override = default;

    [[nodiscard]] bool buildPosition() override;
    [[nodiscard]] bool buildTarget() override;
    [[nodiscard]] bool buildUp() override;
    [[nodiscard]] std::shared_ptr<BaseCameraPTU> getCameraPTU() const override { return _camera; }

    bool isBuilded() override { return (_total == 3); }
    void reset() override { _camera.reset(); };

private:
    int _total{0};

    std::shared_ptr<CameraPTU> _camera;
    std::shared_ptr<BasePTUReader> _reader;
};



#endif //CAMERAPTUBUILDER_HPP
