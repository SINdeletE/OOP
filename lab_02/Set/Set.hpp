#pragma once

#include <cstddef>
#include <memory>

#include "Iterator.hpp"
#include "BaseContainer.hpp"

#include "concept.hpp"

template <numType Type>
class UnorderedSet : public BaseContainer
{
    friend class Iterator;

    private:
        std::shared_ptr<List<Type>> set_ptr;
        std::size_t table_size;
        double load_factor;
    
    public:
        UnorderedSet() noexcept; // Пустой конструктор
        explicit UnorderedSet(const UnorderedSet<Type>&); // Конструктор копирования
        UnorderedSet(UnorderedSet<Type>&); // Конструктор переноса
        ~UnorderedSet();

        explicit UnorderedSet<Type>& operator =(const UnorderedSet<Type>&) // Оператор копирования
        UnorderedSet<Type>& operator=(UnorderedSet<Type>&) // Оператор переноса


        // Основные функции

        std::size_t GetSize() const noexcept override;
        bool IsEmpty() const noexcept override;
};
