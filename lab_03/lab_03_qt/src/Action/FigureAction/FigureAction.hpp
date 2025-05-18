//
// Created by nuelex on 11/05/25.
//

#ifndef FIGUREACTION_HPP
#define FIGUREACTION_HPP
#include <memory>

#include "../BaseAction.hpp"
#include "../../BaseObject/Figure/Figure.hpp"


class FigureAction : public BaseAction
{
public:
    FigureAction() = default;
    FigureAction(const std::shared_ptr<Figure> &figure, const std::shared_ptr<BaseTransform> &transform) { _figure = figure; _transform = transform; }
    ~FigureAction() override = default;

    void request() const override {}

private:
    std::shared_ptr<Figure> _figure;
    std::shared_ptr<BaseTransform> _transform;
};



#endif //FIGUREACTION_HPP
