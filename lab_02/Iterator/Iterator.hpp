#pragma once

#include <cstddef>
#include <cstdbool>

#include <memory>

template <typename Type>
class Iterator : public BaseIterator
{
    private:
        std::weak_ptr<Type []> data_ptr;

    public:
        Iterator(const Iterator<Type>&); // Копирование
        Iterator(const Set<Type []>&); // Перенос
        Iterator(size_t size) = delete; // delete (конструктор с 1-м параметром у итератора быть не может)

        Iterator<Type>& operator =(const Iterator<Type>&);
        Iterator<Type>& operator =(const Set<Type []>&);

        Iterator<Type>& operator ++();
        Iterator<Type> operator ++(int);
        Iterator<Type>& operator --();
        Iterator<Type> operator --(int);
        
        Type& operator [](size_t index);


        
        bool operator <=>(const Iterator<Type>&);
};

#include "iterator.inl"

