//
// Created by nuelex on 13/05/25.
//

#ifndef BASELPREADER_HPP
#define BASELPREADER_HPP
#include <fstream>
#include <string>

#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Links/Links.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"


class BaseLPReader
{
public:
    BaseLPReader() = default;
    explicit BaseLPReader(const std::string &filename);
    virtual ~BaseLPReader() = default;

    [[nodiscard]] virtual Links readLinks() = 0;
    [[nodiscard]] virtual Points readPoints() = 0;
    [[nodiscard]] virtual std::shared_ptr<ConcreteFigureLP> readFigureLP() = 0;

    [[nodiscard]] virtual bool is_open() const = 0;
};



#endif //BASELPREADER_HPP
