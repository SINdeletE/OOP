//
// Created by nuelex on 08/05/25.
//

#include "FigureLP.hpp"

FigureLP::FigureLP(const FigureLP &figure)
{
    links_data = figure.links_data;
    points_data = figure.points_data;
}

FigureLP::FigureLP(const Links &links, const Points &points)
{
    this->links_data = links;
    this->points_data = points;
}
