//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPTUBUILDERCREATOR_HPP
#define CAMERAPTUBUILDERCREATOR_HPP
#include <memory>

#include "BaseCameraPTUBuilder.hpp"


class CameraPTUBuilderCreator
{
public:
    virtual ~CameraPTUBuilderCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BaseCameraPTUBuilder> createFigureLPBuilder(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BaseCameraPTUBuilder, Type> && (! std::is_abstract_v<Type>)
class ConcreteCameraPTUBuilderCreator : public CameraPTUBuilderCreator
{
public:
    ~ConcreteCameraPTUBuilderCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseCameraPTUBuilder> createFigureLPBuilder(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};



#endif //CAMERAPTUBUILDERCREATOR_HPP
