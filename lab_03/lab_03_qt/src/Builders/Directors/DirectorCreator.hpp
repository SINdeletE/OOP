//
// Created by nuelex on 14/05/25.
//

#ifndef DIRECTORCREATOR_HPP
#define DIRECTORCREATOR_HPP
#include <memory>

#include "BaseDirector.hpp"

class DirectorCreator
{
public:
    virtual ~DirectorCreator() = default;
    [[nodiscard]] virtual std::shared_ptr<BaseDirector> createDirector(const std::string &filename) const = 0;
};

template <typename Type>
requires std::is_base_of_v<BaseDirector, Type> && (! std::is_abstract_v<Type>)
class ConcreteDirectorCreator : public DirectorCreator
{
public:
    ~ConcreteDirectorCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseDirector> createDirector(const std::string &filename) const override
    {
        return std::make_shared<Type>(filename);
    }
};


#endif //DIRECTORCREATOR_HPP
