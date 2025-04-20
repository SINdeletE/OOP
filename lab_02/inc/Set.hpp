#pragma once

#include <memory>
#include <initializer_list> 
#include <functional>
#include <stdbool.h>

#include "concept.hpp"
#include "BaseContainer.hpp"
#include "SetIterator.hpp"
#include "ConstSetIterator.hpp"

template <
        keyType Key,
        typename Compare = std::less<Key> // arg1 - arg2
>
class Set : public BaseContainer
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
        Set(Set<Key, Compare> &&set);
        Set(std::initializer_list<Key> nodes);
        // explicit Set(Args&&... args);
        explicit Set(std::size_t n,...);

        ~Set() override = default;

        // Функции для работы с элементами множества
        void erase(const Key &value);
        void erase(iterator &pos);
        // void erase(const_iterator pos);

        void insert(const Key &value);

        // Итераторы
        iterator begin() const noexcept;
        iterator end() const noexcept;
        const_iterator cbegin() const  noexcept;
        const_iterator cend() const noexcept;

        // ИЛИ
        Set<Key, Compare> operator |(const Set<Key, Compare> &);
        Set<Key, Compare> operator |(const Key&);
        Set<Key, Compare>& operator |=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator |=(const Key&);

        Set<Key, Compare> operator +(const Set<Key, Compare> &);
        Set<Key, Compare> operator +(const Key&);
        Set<Key, Compare>& operator +=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator +=(const Key&);

        // И
        Set<Key, Compare> operator &(const Set<Key, Compare> &);
        Set<Key, Compare> operator &(const Key&);
        Set<Key, Compare>& operator &=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator &=(const Key&);

        // Симметрическая разность (Исключающее ИЛИ)
        Set<Key, Compare> operator ^(const Set<Key, Compare> &);
        Set<Key, Compare> operator ^(const Key&);
        Set<Key, Compare>& operator ^=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator ^=(const Key&);
        
        // Разность
        Set<Key, Compare> operator -(const Set<Key, Compare> &);
        Set<Key, Compare> operator -(const Key&);
        Set<Key, Compare>& operator -=(const Set<Key, Compare> &);
        Set<Key, Compare>& operator -=(const Key&);

        // Равенство
        bool operator ==(const Set<Key, Compare> &);
        bool operator !=(const Set<Key, Compare> &);

        [[nodiscard]] std::ptrdiff_t GetSize() const override { return size; };
        bool IsEmpty() const override { return size == 0; };

    private:
        List<Key> data;
};

#include "Set.inl"
