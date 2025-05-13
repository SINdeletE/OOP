//
// Created by nuelex on 09/05/25.
//

#ifndef CONCRETEFIGURELP_HPP
#define CONCRETEFIGURELP_HPP

#include "../BaseConcreteFigure.hpp"
#include "FigureLP/FigureLP.hpp"
#include "Links/Links.hpp"
#include "Point/Points.hpp"
#include "../../../../Transforms/Transforms.hpp"

class ConcreteFigureLP : public BaseConcreteFigure
{
public:
    ConcreteFigureLP() : figureLP_() {}
    explicit ConcreteFigureLP(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; }
    ~ConcreteFigureLP() override = default;

    ConcreteFigureLP& operator=(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; return *this; }

    [[nodiscard]] const Links& getLinks() noexcept override { return figureLP_.getLinks(); }
    [[nodiscard]] const Points& getPoints() noexcept override { return figureLP_.getPoints(); }
    void setLinks(const Links &links) override { figureLP_.setLinks(links); }
    void setLinks(Links &&links) noexcept override { figureLP_.setLinks(std::move(links)); }
    void setPoints(const Points &points) override { figureLP_.setPoints(points); }
    void setPoints(Points &&points) noexcept override { figureLP_.setPoints(std::move(points)); }

    void move(const Mover &mover) override { figureLP_.move(mover); }
    void rotate(const Rotater &rotater) override { figureLP_.rotate(rotater); }
    void scale(const Scaler &scaler) override { figureLP_.scale(scaler); }

private:
    FigureLP figureLP_;
};



#endif //CONCRETEFIGURELP_HPP
