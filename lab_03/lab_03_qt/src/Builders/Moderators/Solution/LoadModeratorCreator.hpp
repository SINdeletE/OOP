//
// Created by nuelex on 25/05/25.
//

#ifndef LOADMODERATORCREATOR_HPP
#define LOADMODERATORCREATOR_HPP
#include <memory>

#include "../BaseLoadModerator.hpp"


class LoadModeratorCreator
{
public:
    LoadModeratorCreator() = default;
    virtual ~LoadModeratorCreator() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseLoadModerator> createLoadModerator() const = 0;
};

template <class T>
requires std::is_base_of<BaseLoadModerator, T>::value && (! std::is_abstract_v<T>)
class ConcreteLoadModeratorCreator : public LoadModeratorCreator
{
public:
    ConcreteLoadModeratorCreator() = default;
    ~ConcreteLoadModeratorCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseLoadModerator> createLoadModerator() const override
    {
        return std::make_shared<T>();
    }
};


#endif //LOADMODERATORCREATOR_HPP
