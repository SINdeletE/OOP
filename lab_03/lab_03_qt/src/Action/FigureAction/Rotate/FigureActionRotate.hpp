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
    FigureActionRotate(const FigureActionRotate& other) : _figure(other._figure), _transform(other._transform) {}
    ~FigureActionRotate() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override;

    void request() const override;

private:
    std::shared_ptr<Figure> _figure;
    std::shared_ptr<Rotater> _transform;
};



#endif //FIGUREACTIONROTATE_HPP
