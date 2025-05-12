//
// Created by nuelex on 08/05/25.
//

#ifndef FIGURELP_HPP
#define FIGURELP_HPP

#include "../Links/Links.hpp"
#include "../Point/Points.hpp"
#include "../../../../../Transforms/Transforms.hpp"

class FigureLP
{
public:
    FigureLP() = default;
    explicit FigureLP(const FigureLP &);
    FigureLP(const Links &, const Points &);
    ~FigureLP() = default;

    [[nodiscard]] const Links& getLinks() noexcept { return links_data; }
    [[nodiscard]] const Points& getPoints() noexcept { return points_data; }

    void setLinks(const Links& links) { links_data = links; }
    void setLinks(Links&& links) noexcept { links_data = std::move(links); }
    void setPoints(const Points& points) { points_data = points; }
    void setPoints(Points&& points) noexcept { points_data = std::move(points); }

    void move(const Mover &);
    void rotate(const Rotater &);
    void scale(const Scaler &);

private:
    void rotate_function(const Rotater &);
    void scale_function(const Scaler &);

    Links links_data;
    Points points_data;
};



#endif //FIGURELP_HPP
