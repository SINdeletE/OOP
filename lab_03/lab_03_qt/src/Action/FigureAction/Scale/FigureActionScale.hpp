//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTIONSCALE_HPP
#define FIGUREACTIONSCALE_HPP
#include "../FigureAction.hpp"


class FigureActionScale : public FigureAction
{
public:
    FigureActionScale() = default;
    ~FigureActionScale() override = default;

    void request() const override {}
};



#endif //FIGUREACTIONSCALE_HPP
