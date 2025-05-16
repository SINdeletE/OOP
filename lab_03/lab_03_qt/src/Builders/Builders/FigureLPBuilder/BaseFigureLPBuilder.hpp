//
// Created by nuelex on 16/05/25.
//

#ifndef BASEFIGURELPBUILDER_HPP
#define BASEFIGURELPBUILDER_HPP
#include <string>

#include "../../BaseBuilder.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/BaseConcreteFigure.hpp"


class BaseFigureLPBuilder : public BaseBuilder
{
public:
    BaseFigureLPBuilder() = delete;
    explicit BaseFigureLPBuilder(const std::string &filename) {}
    ~BaseFigureLPBuilder() override = default;

    bool isBuilded() override { return false; }
    void reset() override {}

    [[nodiscard]] virtual bool buildLinks() = 0;
    [[nodiscard]] virtual bool buildPoints() = 0;
    [[nodiscard]] virtual std::shared_ptr<BaseConcreteFigure> getFigureLP() const = 0;
};



#endif //BASEFIGURELPBUILDER_HPP
