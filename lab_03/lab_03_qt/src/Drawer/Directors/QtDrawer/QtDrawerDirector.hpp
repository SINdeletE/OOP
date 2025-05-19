//
// Created by nuelex on 19/05/25.
//

#ifndef QTDRAWERDIRECTOR_HPP
#define QTDRAWERDIRECTOR_HPP
#include "../../Creator/BaseDrawerDirector.hpp"
#include "../../Drawer/QtDrawer.hpp"


class QtDrawerDirector : public BaseDrawerDirector
{
public:
    QtDrawerDirector() = default;
    ~QtDrawerDirector() override = default;

    std::shared_ptr<BaseDrawer> createDrawer(const BaseColorParameters& color) override;
};



#endif //QTDRAWERDIRECTOR_HPP
