//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTIONROTATE_HPP
#define FIGUREACTIONROTATE_HPP
#include "../FigureAction.hpp"


class FigureActionRotate : public FigureAction
{
public:
    FigureActionRotate() = default;
    ~FigureActionRotate() override = default;

    void request() const override {}
};



#endif //FIGUREACTIONROTATE_HPP
