//
// Created by nuelex on 09/05/25.
//

#ifndef TRANSFORMS_HPP
#define TRANSFORMS_HPP

#include "../Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"

class Mover
{
public:
    Mover() = default;
    Mover(const Mover &) = default;
    Mover(const double dx_, const double dy_, const double dz_, const Point &center_) : dx(dx_), dy(dy_), dz(dz_), center(center_) {}
    ~Mover() = default;

    Mover &operator=(const Mover &) = default;

    void setDx(const double dx_) { dx = dx_; }
    void setDy(const double dy_) { dy = dy_; }
    void setDz(const double dz_) { dz = dz_; }
    void setCenter(const Point &center_) { center = center_; }

private:
    double dx;
    double dy;
    double dz;
    Point center;
};

class Rotater
{
public:
    Rotater() = default;
    Rotater(const Rotater &) = default;
    Rotater(const double ox_, const double oy_, const double oz_, const Point &center_) : ox(ox_), oy(oy_), oz(oz_), center(center_) {}
    ~Rotater() = default;

    Rotater &operator=(const Rotater &) = default;

    void setOx(const double ox_) { ox = ox_; }
    void setOy(const double oy_) { oy = oy_; }
    void setOz(const double oz_) { oz = oz_; }
    void setCenter(const Point &center_) { center = center_; }

    const Mover& centerToMover();

private:
    double ox;
    double oy;
    double oz;
    Point center;
};

class Scaler
{
public:
    Scaler() = default;
    Scaler(const Scaler &) = default;
    Scaler(const double kx_, const double ky_, const double kz_, const Point &center_) : kx(kx_), ky(ky_), kz(kz_), center(center_) {}
    ~Scaler() = default;

    Scaler &operator=(const Scaler &) = default;

    void setKx(const double kx_) { kx = kx_; }
    void setKy(const double ky_) { ky = ky_; }
    void setKz(const double kz_) { kz = kz_; }
    void setCenter(const Point &center_) { center = center_; }

    const Mover& centerToMover();

private:
    double kx;
    double ky;
    double kz;
    Point center;
};

#endif //TRANSFORMS_HPP
