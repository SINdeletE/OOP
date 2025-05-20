//
// Created by nuelex on 20/05/25.
//

#ifndef QTDRAWERBUILDER_HPP
#define QTDRAWERBUILDER_HPP
#include "BaseQtDrawerBuilder.hpp"


class QtDrawerBuilder : public BaseQtDrawerBuilder
{
public:
    QtDrawerBuilder() = delete;
    explicit QtDrawerBuilder(const std::shared_ptr<BaseColorParameters> &color_parameters) : \
                               BaseQtDrawerBuilder(color_parameters), _color_parameters(color_parameters) {}
    ~QtDrawerBuilder() override = default;

    bool isBuilded() override { return false; }
    void reset() override {}

    void buildColor() override;
    void buildPen() override;

    std::shared_ptr<BaseDrawer> getDrawer() override { return nullptr; }

private:
    std::shared_ptr<BaseColorParameters> _color_parameters;
    
    std::shared_ptr<BaseDrawer> _drawer;
};



#endif //QTDRAWERBUILDER_HPP
