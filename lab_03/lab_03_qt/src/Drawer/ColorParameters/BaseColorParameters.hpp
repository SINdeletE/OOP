//
// Created by nuelex on 19/05/25.
//

#ifndef BASECOLORPARAMETERS_HPP
#define BASECOLORPARAMETERS_HPP



class BaseColorParameters
{
public:
    BaseColorParameters() = delete;
    BaseColorParameters(int r, int g, int b);
    BaseColorParameters(const BaseColorParameters&) = default;

    BaseColorParameters& operator=(const BaseColorParameters&) = default;

    virtual ~BaseColorParameters() = default;

    virtual void setR(int r) = 0;
    virtual void setG(int g) = 0;
    virtual void setB(int b) = 0;
    [[nodiscard]] virtual int getR() const = 0;
    [[nodiscard]] virtual int getG() const = 0;
    [[nodiscard]] virtual int getB() const = 0;
};



#endif //BASECOLORPARAMETERS_HPP
