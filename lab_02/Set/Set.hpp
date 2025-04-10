#pragma once

#include <cstddef>
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
        Set() noexcept; // Пустой конструктор
        explicit Set(const Set<Type>&); // Конструктор копирования
        Set(Set<Type>&); // Конструктор переноса
        ~Set();

        explicit Set<Type>& operator =(const Set<Type>&) // Оператор копирования
        Set<Type>& operator=(Set<Type>&) // Оператор переноса


        // Основные функции

        std::size_t GetSize() const noexcept override;
        bool IsEmpty() const noexcept override;
};
