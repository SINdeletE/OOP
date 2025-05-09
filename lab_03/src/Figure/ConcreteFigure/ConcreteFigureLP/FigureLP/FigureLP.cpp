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

void FigureLP::rotate_function(const Rotater &rotater)
{
    Points pts = this->getPoints();
    PointsIterator<Point, Points> iterator(pts);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->rotate(rotater.getOx(), rotater.getOy(), rotater.getOz());
}

void FigureLP::scale_function(const Scaler &scaler)
{
    Points pts = this->getPoints();
    PointsIterator<Point, Points> iterator(pts);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->scale(scaler.getKx(), scaler.getKy(), scaler.getKz());
}

void FigureLP::move(const Mover &mover)
{
    Points pts = this->getPoints();
    PointsIterator<Point, Points> iterator(pts);

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        iterator.Current()->move(mover.getDx(), mover.getDy(), mover.getDz());
}

void FigureLP::rotate(const Rotater &rotater)
{
    Points pts = this->getPoints();
    PointsIterator<Point, Points> iterator(pts);

    this->move(-rotater.centerToMover());
    this->rotate_function(rotater);
    this->move(-rotater.centerToMover());
}

void FigureLP::scale(const Scaler &scaler)
{
    Points pts = this->getPoints();
    PointsIterator<Point, Points> iterator(pts);

    this->move(-scaler.centerToMover());
    this->scale_function(scaler);
    this->move(-scaler.centerToMover());
}
