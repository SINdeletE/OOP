#pragma once

#include <cstddef>
#include <cstdbool>

#include <memory>

#include "concept.hpp"

template <typename Type>
class Iterator : public BaseIterator
{
    private:
        std::weak_ptr<Type []> data_ptr;

    public:
        Iterator(const Iterator<Type>&); // Копирование
        Iterator(const Set<Type []>&); // Перенос
        Iterator(size_t size) = delete; // delete (конструктор с 1-м параметром у итератора быть не может)
        ~Iterator() override; // Деструктор (так-то для weak_ptr не нужно особо)

        Iterator<Type>& operator =(const Iterator<Type>&);
        Iterator<Type>& operator =(const Set<Type []>&);

        template <sizeType U> Iterator<Type>& operator+=(const U value);
        template <sizeType U> Iterator<Type>& operator-=(const U value);
        template <sizeType U> Iterator<Type> operator+(const U value) const;
        template <sizeType U> Iterator<Type> operator-(const U value) const;

        Iterator<Type>& operator ++();
        Iterator<Type> operator ++(int);
        Iterator<Type>& operator --();
        Iterator<Type> operator --(int);
        
        Type& operator [](size_t index);

        bool operator bool()() const noexcept;
        
        auto operator <=>(const Iterator<Type>&) const;
};

#include "iterator.inl"

