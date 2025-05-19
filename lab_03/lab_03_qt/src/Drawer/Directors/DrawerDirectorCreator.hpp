//
// Created by nuelex on 19/05/25.
//

#ifndef DRAWERDIRECTORCREATOR_HPP
#define DRAWERDIRECTORCREATOR_HPP
#include <memory>

#include "../../Exceptions/Drawer/DrawerException.hpp"
#include "../Creator/BaseDrawerDirector.hpp"


class DrawerDirectorCreator
{
public:
    DrawerDirectorCreator() = default;
    virtual ~DrawerDirectorCreator() = default;

    virtual std::shared_ptr<BaseDrawerDirector> createDirector(const BaseColorParameters& params) const = 0;
};

template <class T>
requires std::is_base_of_v<BaseDrawerDirector, T> && ! std::is_abstract_v<T>
class ConcreteDrawerDirectorCreator : public DrawerDirectorCreator
{
public:
    ConcreteDrawerDirectorCreator() = default;
    ~ConcreteDrawerDirectorCreator() override = default;

    std::shared_ptr<BaseDrawerDirector> createDirector(const BaseColorParameters& params) const override
    {
        try
        {
            return std::make_shared<T>(params);
        }
        catch (ErrorDrawer_bad_alloc &e)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }
};



#endif //DRAWERDIRECTORCREATOR_HPP
