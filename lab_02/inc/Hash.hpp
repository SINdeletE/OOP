#pragma once

#include <cstddef>
#include <memory>
#include <initializer_list>
#include <utility>

#include "ListIterator.hpp"
#include "ConstListIterator.hpp"
#include "BaseContainer.hpp"

#include "concept.hpp"

template <keyType Key, numType Type, 
        typename Hash = hash<Key>, 
        typename Pred = equal_to<Key>>
class UnorderedMap : public BaseContainer
{
    friend class Iterator;
    
    public:
        using key_type             = Key;
        using mapped_type          = Type;
        using reference            = Type&;
        using const_reference      = const Type&;
        using size_type            = std::ptrdiff_t;
        using value_type           = pair<const Key, Type>;
        using hasher               = Hash;
        using key_equal            = Pred;
        using reference            = value_type&;
        using const_reference      = const value_type&;

        using iterator = UnorderedMapIterator<Type>;
        using const_iterator = ConstUnorderedMapIterator<Type>;
        using local_iterator       = ListIterator<Type>;
        using const_local_iterator = ConstListIterator<Type>;

        UnorderedMap() noexcept; // Пустой конструктор
        explicit UnorderedMap(const UnorderedMap<Type>&); // Конструктор копирования
        UnorderedMap(UnorderedMap<Type>&); // Конструктор переноса
        UnorderedMap(std::initializer_list<Key>); // Инициализация с переменным числом параметров
        UnorderedMap(Args&&... args); // Переменно
        // UnorderedMap(R&& range); // Диапазон

        ~UnorderedMap();

        explicit UnorderedMap<Type>& operator =(const UnorderedMap<Type>&); // Оператор копирования
        UnorderedMap<Type>& operator=(UnorderedMap<Type>&); // Оператор переноса


        // Основные функции

        std::size_t GetSize() const noexcept override;
        bool IsEmpty() const noexcept override;
    
    private:
        List<<List<Type>>> buckets;
        std::ptrdiff_t table_size;
        sid::ptrdiff_t capacity;
        double load_factor;

        void BucketsAlloc(size_type size);
};

// static_assert(ContainerConcept<UnorderedMap<int>>);

#include "Hash.inl"
