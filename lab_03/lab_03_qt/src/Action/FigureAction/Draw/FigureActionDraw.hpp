//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTIONDRAW_HPP
#define FIGUREACTIONDRAW_HPP
#include "../FigureAction.hpp"

class FigureActionDraw : public FigureAction
{
public:
    FigureActionDraw() = default;
    ~FigureActionDraw() override = default;

    void request() const override {}
};

#endif //FIGUREACTIONDRAW_HPP
