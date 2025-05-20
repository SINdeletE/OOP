//
// Created by nuelex on 19/05/25.
//

#ifndef QTDRAWERDIRECTOR_HPP
#define QTDRAWERDIRECTOR_HPP
#include "../../Builders/QtDrawer/BaseQtDrawerBuilder.hpp"
#include "../../Factory/BaseDrawerDirector.hpp"
#include "../../Drawer/QtDrawer.hpp"


class QtDrawerDirector : public BaseDrawerDirector
{
public:
    QtDrawerDirector() = default;
    ~QtDrawerDirector() override = default;

    std::shared_ptr<BaseDrawer> createDrawer(const std::shared_ptr<BaseColorParameters> &color) override;

private:
    std::shared_ptr<QtDrawer> _drawer;
    std::shared_ptr<BaseQtDrawerBuilder> _builder;
};



#endif //QTDRAWERDIRECTOR_HPP
