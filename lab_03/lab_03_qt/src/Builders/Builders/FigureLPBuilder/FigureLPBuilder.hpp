//
// Created by nuelex on 16/05/25.
//

#ifndef FIGURELPBUILDER_HPP
#define FIGURELPBUILDER_HPP
#include "BaseFigureLPBuilder.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"
#include "../../Readers/LPReaders/BaseLPReader.hpp"


class FigureLPBuilder : public BaseFigureLPBuilder
{
public:
    FigureLPBuilder() = delete;
    explicit FigureLPBuilder(const std::string &string);
    ~FigureLPBuilder() override = default;

    bool isBuilded() override { return bool(FigureLP_); }
    void reset() override { FigureLP_.reset(); }

    [[nodiscard]] bool buildLinks() override;
    [[nodiscard]] bool buildPoints() override;
    [[nodiscard]] std::shared_ptr<BaseConcreteFigure> getFigureLP() const override { return FigureLP_; }

private:
    Links _links;
    Points _points;
    std::shared_ptr<ConcreteFigureLP> FigureLP_;
    std::shared_ptr<BaseLPReader> reader_;
};



#endif //FIGURELPBUILDER_HPP
