#pragma once

#include <iostream>
#include <memory>
#include <initializer_list> 
#include <functional>
#include <stdbool.h>
#include <cstdarg>

#include "concept.hpp"
#include "BaseContainer.hpp"
#include "SetIterator.hpp"
#include "ConstSetIterator.hpp"

template <
        keyType Key,
        typename Compare = std::less<Key> // arg1 - arg2
>
class Set final: public BaseContainer
{
    friend class SetIterator<Key>;
    friend class ConstSetIterator<Key>;

    using key_type	        =Key;
    using value_type	    =Key;
    using size_type	        =std::ptrdiff_t;
    using difference_type	=std::ptrdiff_t;
    using key_compare	    =Compare;
    using value_compare     =Compare;
    using reference	        =value_type&;
    using const_reference	=const value_type&;
    using iterator          =SetIterator<Key>;
    using const_iterator    =ConstSetIterator<Key>;
    using node_type         =Node<Key>;

    public:
        Set() : data() { this->size = 0; };

        explicit Set(const Set<Key, Compare> &set);
        Set(Set<Key, Compare> &&set) noexcept;
        Set(std::initializer_list<Key> list);
        // explicit Set(Args&&... args);
        explicit Set(std::ptrdiff_t n,...);
        Set(size_type array_len, const Key *array);

        Set<Key, Compare>& operator=(const Set<Key, Compare> &set);
        Set<Key, Compare>& operator=(Set<Key, Compare> &&set) noexcept;

        ~Set() override = default;

        // Функции для работы с элементами множества
        iterator erase(const Key &value);
        iterator erase(iterator &pos);
        const_iterator erase(const_iterator &pos);

        iterator find(const Key &value) const;
        const_iterator cfind(const Key &value) const;
        
        void clear();
        iterator insert(const Key &value);
        bool contains(const Key &value) const { return this->find(value) != this->end(); }

        // Итераторы
        iterator begin() const noexcept;
        iterator end() const noexcept;
        const_iterator cbegin() const  noexcept;
        const_iterator cend() const noexcept;

        // ИЛИ
        Set<Key, Compare> operator |(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator |(const Key&) const;
        Set<Key, Compare>& operator |=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator |=(const Key&);

        Set<Key, Compare> operator +(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator +(const Key&) const;
        Set<Key, Compare>& operator +=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator +=(const Key&);

        // И
        Set<Key, Compare> operator &(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator &(const Key&) const;
        Set<Key, Compare>& operator &=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator &=(const Key&);

        // Симметрическая разность (Исключающее ИЛИ)
        Set<Key, Compare> operator ^(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator ^(const Key&) const;
        Set<Key, Compare>& operator ^=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator ^=(const Key&);
        
        // Разность
        Set<Key, Compare> operator -(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator -(const Key&) const;
        Set<Key, Compare>& operator -=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator -=(const Key&);

        // Равенство
        bool operator ==(const Set<Key, Compare> &);
        bool operator !=(const Set<Key, Compare> &);

        [[nodiscard]] std::ptrdiff_t GetSize() const noexcept override { return size; }
        bool IsEmpty() const noexcept override { return size == 0; }

    private:
        List<Key> data;
};

template <
        keyType Key, 
        typename Compare = std::less<Key>
>
std::ostream& operator <<(std::ostream &os, Set<Key, Compare> &set)
{
    for (const auto &v : set)
        os << v << ' ';

    os << std::endl;

    return os;
}

#include "Set.inl"
