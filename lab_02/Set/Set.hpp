#pragma once

#include <memory>

#include "Iterator.hpp"
#include "BaseSet.hpp"

#include "concept.hpp"

template <numType Type>
class Set : public BaseSet
{
    friend class Iterator;

    private:
        std::shared_ptr<Type []> set_ptr;
    
    public:
        Set() noexcept;
        explicit Set(const Set<Type>&); // Конструктор копирования
        Set(Set<Type>&); // Конструктор переноса
};
