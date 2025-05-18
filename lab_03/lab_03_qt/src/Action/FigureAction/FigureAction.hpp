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
    FigureAction(const std::shared_ptr<Figure> &figure, const std::shared_ptr<BaseTransform> &transform) {}
    ~FigureAction() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override {}

    void request() const override {}
};



#endif //FIGUREACTION_HPP
