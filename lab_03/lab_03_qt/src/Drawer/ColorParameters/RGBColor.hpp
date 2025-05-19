//
// Created by nuelex on 19/05/25.
//

#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP
#include "BaseColorParameters.hpp"


class RGBColor : public BaseColorParameters
{
public:
    RGBColor() = delete;
    RGBColor(const int r, const int g, const int b) : BaseColorParameters(r, g, b), _r(r), _g(g), _b(b) {}
    RGBColor(const RGBColor& other) = default;

    RGBColor& operator=(const RGBColor& other) = default;

    ~RGBColor() override = default;

    void setR(const int r) override { _r = r; }
    void setG(const int g) override { _g = g; }
    void setB(const int b) override { _b = b; }
    [[nodiscard]] int getR() const override { return _r; }
    [[nodiscard]] int getG() const override { return _g; }
    [[nodiscard]] int getB() const override { return _b; }

private:
    int _r;
    int _g;
    int _b;
};



#endif //RGBCOLOR_HPP
