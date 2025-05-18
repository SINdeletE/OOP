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
    FigureActionScale(const FigureActionScale& other) : _figure(other._figure), _transform(other._transform) {}
    ~FigureActionScale() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override;

    void request() const override;

private:
    std::shared_ptr<Figure> _figure;
    std::shared_ptr<Scaler> _transform;
};



#endif //FIGUREACTIONSCALE_HPP
