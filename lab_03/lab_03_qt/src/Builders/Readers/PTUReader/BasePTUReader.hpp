//
// Created by nuelex on 16/05/25.
//

#ifndef BASEPDUREADER_HPP
#define BASEPDUREADER_HPP
#include <string>

#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"


class BasePTUReader
{
public:
    BasePTUReader() = default;
    explicit BasePTUReader(const std::string &filename);
    virtual ~BasePTUReader() = default;

    [[nodiscard]] virtual Point readPosition() = 0;
    [[nodiscard]] virtual Point readTarget() = 0;
    [[nodiscard]] virtual Point readUp() = 0;

    [[nodiscard]] virtual bool is_open() const = 0;
};



#endif //BASEPDUREADER_HPP
