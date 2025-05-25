//
// Created by nuelex on 16/05/25.
//

#ifndef BASEFIGURELPBUILDER_HPP
#define BASEFIGURELPBUILDER_HPP
#include <string>

#include "../../../BaseObject/Figure/ConcreteFigure/BaseConcreteFigureLP.hpp"
#include "../../Readers/LPReaders/BaseLPReader.hpp"


class BaseFigureLPBuilder
{
public:
    BaseFigureLPBuilder() = delete;
    explicit BaseFigureLPBuilder(const std::shared_ptr<BaseLPReader> &reader) {}
    virtual ~BaseFigureLPBuilder() = default;

    virtual bool isBuilded() { return false; }
    virtual void reset() {}

    [[nodiscard]] virtual bool buildLinks() = 0;
    [[nodiscard]] virtual bool buildPoints() = 0;
    [[nodiscard]] virtual std::shared_ptr<BaseConcreteFigureLP> getFigureLP() const = 0;
};



#endif //BASEFIGURELPBUILDER_HPP
