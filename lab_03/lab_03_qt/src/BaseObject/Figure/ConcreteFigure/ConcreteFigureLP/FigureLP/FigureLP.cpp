//
// Created by nuelex on 08/05/25.
//

#include "FigureLP.hpp"

FigureLP::FigureLP(const FigureLP &figure)
{
    links_data = figure.links_data;
    points_data = figure.points_data;
}

FigureLP::FigureLP(FigureLP &&figure) noexcept
{
    links_data = std::move(figure.links_data);
    points_data = std::move(figure.points_data);
}

FigureLP::FigureLP(const Links &links, const Points &points)
{
    this->links_data = links;
    this->points_data = points;
}

FigureLP::FigureLP(Links &&links, Points &&points) noexcept
{
    this->links_data = std::move(links);
    this->points_data = std::move(points);
}

void FigureLP::rotate_function(const Rotater &rotater)
{
    PointsIterator<Point, Points> iterator(points_data);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->rotate(rotater.getOx(), rotater.getOy(), rotater.getOz());
}

void FigureLP::scale_function(const Scaler &scaler)
{
    PointsIterator<Point, Points> iterator(points_data);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->scale(scaler.getKx(), scaler.getKy(), scaler.getKz());
}

void FigureLP::transform(const Mover &mover)
{
    PointsIterator<Point, Points> iterator(points_data);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->move(mover.getDx(), mover.getDy(), mover.getDz());
}

void FigureLP::transform(const Rotater &rotater)
{
    PointsIterator<Point, Points> iterator(points_data);

    this->transform(-rotater.centerToMover());
    this->rotate_function(rotater);
    this->transform(-rotater.centerToMover());
}

void FigureLP::transform(const Scaler &scaler)
{
    PointsIterator<Point, Points> iterator(points_data);

    this->transform(-scaler.centerToMover());
    this->scale_function(scaler);
    this->transform(-scaler.centerToMover());
}
