//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTIONZBUFFER_HPP
#define FIGUREACTIONZBUFFER_HPP
#include "../FigureAction.hpp"


class FigureActionZBuffer : public FigureAction
{
public:
    FigureActionZBuffer() = default;
    ~FigureActionZBuffer() override = default;

    void request() const override {}
};



#endif //FIGUREACTIONZBUFFER_HPP
