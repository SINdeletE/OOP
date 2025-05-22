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
    FigureLP(FigureLP &&) noexcept;
    FigureLP(const Links &, const Points &);
    FigureLP(Links &&links, Points &&points) noexcept;
    ~FigureLP() = default;

    FigureLP &operator=(const FigureLP &other) { links_data = other.links_data; points_data = other.points_data; return *this; }
    FigureLP &operator=(FigureLP &&other) noexcept { links_data = std::move(other.links_data); points_data = std::move(other.points_data); return *this; }

    [[nodiscard]] const Links& getLinks() const noexcept { return links_data; }
    [[nodiscard]] const Points& getPoints() const noexcept { return points_data; }

    void setLinks(const Links& links) { links_data = links; }
    void setLinks(Links&& links) noexcept { links_data = std::move(links); }
    void setPoints(const Points& points) { points_data = points; }
    void setPoints(Points&& points) noexcept { points_data = std::move(points); }

    void transform(const Mover &);
    void transform(const Rotater &);
    void transform(const Scaler &);

private:
    void rotate_function(const Rotater &);
    void scale_function(const Scaler &);

    Links links_data;
    Points points_data;

    static Rotater radFromDegree(const Rotater &rotater);
};



#endif //FIGURELP_HPP
