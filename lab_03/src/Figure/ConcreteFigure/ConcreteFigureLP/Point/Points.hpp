//
// Created by nuelex on 08/05/25.
//

#ifndef POINTS_HPP
#define POINTS_HPP

#include <list>

#include "PointsIterator.hpp"

class Point
{
private:
    double x;
    double y;
    double z;

public:
    Point() = default;
    Point(const double &x_value, const double &y_value, const double &z_value) : x(x_value), y(y_value), z(z_value) {}

    [[nodiscard]] double GetX() const noexcept { return x; }
    [[nodiscard]] double GetY() const noexcept { return y; }
    [[nodiscard]] double GetZ() const noexcept { return z; }
    void SetX(const double &x) noexcept { this->x = x; }
    void SetY(const double &y) noexcept { this->y = y; }
    void SetZ(const double &z) noexcept { this->z = z; }
};

class Points
{
private:
    std::list<Point> points;

public:
    using point_type = Point;
    using iterator = PointsIterator<point_type, Points>;
    using const_iterator = PointsIterator<const point_type, Points>;

    friend class PointsIterator<point_type, Points>;
    friend class PointsIterator<const point_type, Points>;

    Points() = default;
    Points(const Points &points_arg) { points = points_arg.points; }
    ~Points() = default;

    Points& operator =(const Points &points_arg);

    void AddPoint(const double &x, const double &y, const double &z);

    [[nodiscard]] std::size_t size() const noexcept { return points.size(); }
    [[nodiscard]] bool empty() const noexcept { return points.empty(); }

    iterator CreateIterator() { return iterator(*this); }
};

#endif //POINTS_HPP
