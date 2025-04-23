#pragma once

#include <iostream>
#include <memory>
#include <ranges>
#include <initializer_list> 
#include <functional>
#include <stdbool.h>
#include <cstdarg>

#include "concept.hpp"
#include "List.hpp"
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
        Set() noexcept : data() { this->size = 0; };

        explicit Set(const Set<Key, Compare> &set);
        Set(Set<Key, Compare> &&set) noexcept;
        Set(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set(std::initializer_list<U> list);
        Set(size_type array_len, const Key *array);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set(size_type array_len, const U *array);
        template <std::input_iterator Beg, std::sentinel_for<Beg> End>
        requires std::convertible_to<std::iter_value_t<Beg>, Key>
        Set(Beg begin, End end);

        // Операторы =
        Set<Key, Compare>& operator=(const Set<Key, Compare> &set);
        Set<Key, Compare>& operator=(Set<Key, Compare> &&set) noexcept;
        Set<Key, Compare>& operator=(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set<Key, Compare>& operator=(std::initializer_list<U> list);

        ~Set() override = default;

        // Функции для работы с элементами множества
        iterator erase(const Key &value);
        template <keyType U>
        requires Convertible_concept<U, Key>
        iterator erase(const U &value) { return this->erase(static_cast<Key>(value)); }
        iterator erase(iterator &pos);
        const_iterator erase(const_iterator &pos);

        iterator find(const Key &value) const;
        const_iterator cfind(const Key &value) const;
        
        void clear();
        
        iterator insert(const Key &value);
        template <keyType U>
        requires Convertible_concept<U, Key>
        iterator insert(const U &value);

        bool contains(const Key &value) const { return this->find(value) != this->end(); }

        // Итераторы
        iterator begin() const noexcept;
        iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
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
        Set<Key, Compare>& Or(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set<Key, Compare>& Or(std::initializer_list<U> list);

        // И
        Set<Key, Compare> operator &(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator &(const Key&) const;
        Set<Key, Compare>& operator &=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator &=(const Key&);
        Set<Key, Compare> operator *(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator *(const Key&) const;
        Set<Key, Compare>& operator *=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator *=(const Key&);
        Set<Key, Compare>& And(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set<Key, Compare>& And(std::initializer_list<U> list);

        // Симметрическая разность (Исключающее ИЛИ)
        Set<Key, Compare> operator ^(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator ^(const Key&) const;
        Set<Key, Compare>& operator ^=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator ^=(const Key&);
        Set<Key, Compare>& Xor(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set<Key, Compare>& Xor(std::initializer_list<U> list);
        
        // Разность
        Set<Key, Compare> operator -(const Set<Key, Compare> &) const;
        Set<Key, Compare> operator -(const Key&) const;
        Set<Key, Compare>& operator -=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator -=(const Key&);
        Set<Key, Compare>& Diff(std::initializer_list<Key> list);
        template <keyType U>
        requires Convertible_concept<U, Key>
        Set<Key, Compare>& Diff(std::initializer_list<U> list);

        // Равенство
        bool operator ==(const Set<Key, Compare> &) const;
        bool operator !=(const Set<Key, Compare> &) const;

        [[nodiscard]] size_type GetSize() const noexcept override { return size; }
        bool IsEmpty() const noexcept override { return size == 0; }

    private:
        List<Key> data;
};

template <
        keyType Key, 
        typename Compare = std::less<Key>
>
requires Printable_concept<Key>
std::ostream& operator <<(std::ostream &os, Set<Key, Compare> &set)
{
    for (const auto &v : set)
        os << v << ' ';

    os << std::endl;

    return os;
}

#include "Set.inl"
