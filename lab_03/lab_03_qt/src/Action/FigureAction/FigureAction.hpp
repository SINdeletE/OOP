//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTION_HPP
#define FIGUREACTION_HPP
#include "../BaseAction.hpp"


class FigureAction : public BaseAction
{
public:
    FigureAction() = default;
    ~FigureAction() override = default;

    void request() const override {}
};



#endif //FIGUREACTION_HPP
