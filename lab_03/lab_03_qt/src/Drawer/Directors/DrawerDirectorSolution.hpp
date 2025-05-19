//
// Created by nuelex on 19/05/25.
//

#ifndef DRAWERSOLUTION_HPP
#define DRAWERSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "DrawerDirectorCreator.hpp"
#include "DrawerDirectorHash.hpp"
#include "../Graphics/BaseGraphics.hpp"


class DrawerDirectorSolution
{
public:
    DrawerDirectorSolution();
    ~DrawerDirectorSolution() = default;

    std::shared_ptr<BaseDrawerDirector> createDrawer(const std::shared_ptr<BaseGraphics> &graphics, const BaseColorParameters& params);
    void reg(std::pair<std::shared_ptr<BaseGraphics>, std::unique_ptr<DrawerDirectorCreator>> &&other);

private:
    std::unordered_map<std::shared_ptr<BaseGraphics>, std::unique_ptr<DrawerDirectorCreator>, DrawerDirectorHash> _creators;
};



#endif //DRAWERSOLUTION_HPP
