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
    FigureActionMove(const FigureActionMove& other) : _figure(other._figure), _transform(other._transform) {}
    ~FigureActionMove() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override;

    void request() const override;

private:
    std::shared_ptr<Figure> _figure;
    std::shared_ptr<Mover> _transform;
};



#endif //FIGUREACTIONMOVE_HPP
