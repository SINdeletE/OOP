//
// Created by nuelex on 16/05/25.
//

#ifndef BASEPDUREADER_HPP
#define BASEPDUREADER_HPP
#include <string>

#include "../BaseReader.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"


class BasePDUReader : public BaseReader
{
public:
    BasePDUReader() = default;
    explicit BasePDUReader(const std::string &filename);
    ~BasePDUReader() override = default;

    [[nodiscard]] virtual Point readPosition() = 0;
    [[nodiscard]] virtual Point readTarget() = 0;
    [[nodiscard]] virtual Point readUp() = 0;

    [[nodiscard]] virtual bool is_open() const = 0;
};



#endif //BASEPDUREADER_HPP
