//
// Created by nuelex on 16/05/25.
//

#ifndef FIGURELPBUILDERCREATOR_HPP
#define FIGURELPBUILDERCREATOR_HPP
#include <memory>

#include "BaseFigureLPBuilder.hpp"


class FigureLPBuilderCreator
{
public:
    virtual ~FigureLPBuilderCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BaseFigureLPBuilder> createFigureLPBuilder(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BaseFigureLPBuilder, Type> && (! std::is_abstract_v<Type>)
class ConcreteLPBuilderCreator : public FigureLPBuilderCreator
{
public:
    ~ConcreteLPBuilderCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseFigureLPBuilder> createFigureLPBuilder(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};



#endif //FIGURELPBUILDERCREATOR_HPP
