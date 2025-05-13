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

    void rotateX(double angle); // так-то const, но в определении (clang воспринимает const только в определении)
    void rotateY(double angle);
    void rotateZ(double angle);

public:
    Point() = default;
    Point(const double &x_value, const double &y_value, const double &z_value) : x(x_value), y(y_value), z(z_value) {}

    Point& operator =(const Point &other) { x = other.x; y = other.y; z = other.z; return *this; }

    [[nodiscard]] double GetX() const noexcept { return x; }
    [[nodiscard]] double GetY() const noexcept { return y; }
    [[nodiscard]] double GetZ() const noexcept { return z; }
    void SetX(const double &x) noexcept { this->x = x; }
    void SetY(const double &y) noexcept { this->y = y; }
    void SetZ(const double &z) noexcept { this->z = z; }

    Point operator -() const noexcept;

    void move(const double &dx, const double &dy, const double &dz) noexcept { this->x += dx; this->y += dy; this->z += dz; }
    void rotate(const double &ox, const double &oy, const double &oz) noexcept { rotateX(ox); rotateY(oy); rotateZ(oz); }
    void scale(const double &kx, const double &ky, const double &kz) noexcept { this->x *= kx; this->y *= ky; this->z *= kz; }
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
    explicit Points(const Points &points_arg) { points = points_arg.points; }
    Points(Points &&points_arg) noexcept { points = std::move(points_arg.points); }
    ~Points() = default;

    Points& operator =(const Points &points_arg);
    Points& operator =(Points &&points_arg) noexcept { this->points = std::move(points_arg.points); return *this; }

    void AddPoint(const double &x, const double &y, const double &z);
    void AddPoint(const Point &point) { this->AddPoint(point.GetX(), point.GetY(), point.GetZ()); }

    [[nodiscard]] std::size_t size() const noexcept { return points.size(); }
    [[nodiscard]] bool empty() const noexcept { return points.empty(); }

    iterator CreateIterator() { return iterator(*this); }
};

#endif //POINTS_HPP
