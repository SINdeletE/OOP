//
// Created by nuelex on 08/05/25.
//

#ifndef FIGURELP_HPP
#define FIGURELP_HPP

#include "../Links/Links.hpp"
#include "../Point/Points.hpp"
#include "../../../../Transforms/Transforms.hpp"

class FigureLP
{
public:
    FigureLP() = default;
    FigureLP(const FigureLP &);
    FigureLP(const Links &, const Points &);
    ~FigureLP() = default;

    [[nodiscard]] const Links& getLinks() const noexcept { return links_data; }
    [[nodiscard]] const Points& getPoints() const noexcept { return points_data; }
    void setLinks(const Links& links) { links_data = links; }
    void setPoints(const Points& points) { points_data = points; }

    void move(const Mover &);
    void rotate(const Rotater &);
    void scale(const Scaler &);

private:
    Links links_data;
    Points points_data;
};



#endif //FIGURELP_HPP
