//
// Created by nuelex on 09/05/25.
//

#ifndef CONCRETEFIGURELP_HPP
#define CONCRETEFIGURELP_HPP

#include "../BaseConcreteFigure.hpp"
#include "FigureLP/FigureLP.hpp"
#include "Links/Links.hpp"
#include "Point/Points.hpp"

class ConcreteFigureLP : public BaseConcreteFigure
{
protected:
    ConcreteFigureLP() = default;
    ConcreteFigureLP(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; }
    ~ConcreteFigureLP() override = default;

    ConcreteFigureLP& operator=(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; return *this; }

public:
    [[nodiscard]] const Links &getLinks() const noexcept { return figureLP_.getLinks(); }
    [[nodiscard]] const Points &getPoints() const noexcept override { return figureLP_.getPoints(); }
    void setLinks(const Links &links) { figureLP_.setLinks(links); }
    void setPoints(const Points &points) override { figureLP_.setPoints(points); }

private:
    FigureLP figureLP_;
};



#endif //CONCRETEFIGURELP_HPP
