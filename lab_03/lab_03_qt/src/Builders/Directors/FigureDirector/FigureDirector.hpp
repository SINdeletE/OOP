//
// Created by nuelex on 14/05/25.
//

#ifndef FIGUREDIRECTOR_HPP
#define FIGUREDIRECTOR_HPP
#include <string>

#include "../BaseDirector.hpp"


class FigureDirector : public BaseDirector
{
public:
    FigureDirector() = default;
    explicit FigureDirector(const std::string &filename) {}
    ~FigureDirector() override = default;

    void create() override {}
};



#endif //FIGUREDIRECTOR_HPP
