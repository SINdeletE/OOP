//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTIONMOVE_HPP
#define FIGUREACTIONMOVE_HPP
#include "../FigureAction.hpp"


class FigureActionMove : public FigureAction
{
public:
    FigureActionMove() = default;
    ~FigureActionMove() override = default;

    void request() const override {}
};



#endif //FIGUREACTIONMOVE_HPP
