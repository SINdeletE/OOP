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
    explicit FigureLPBuilder(const std::shared_ptr<BaseLPReader> &reader);
    ~FigureLPBuilder() override = default;

    bool isBuilded() override { return (_total == 2); }
    void reset() override { FigureLP_.reset(); }

    [[nodiscard]] bool buildLinks() override;
    [[nodiscard]] bool buildPoints() override;
    [[nodiscard]] std::shared_ptr<BaseConcreteFigureLP> getFigureLP() const override { return std::make_shared<ConcreteFigureLP>(FigureLP_); }

private:
    int _total{0};

    std::shared_ptr<FigureLP> FigureLP_;
    std::shared_ptr<BaseLPReader> reader_;
};



#endif //FIGURELPBUILDER_HPP
