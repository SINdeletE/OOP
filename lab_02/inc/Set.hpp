#pragma once

#include <cstddef>
#include <memory>

#include "Iterator.hpp"
#include "BaseContainer.hpp"

#include "concept.hpp"

template <typename Key, keyType Type, 
        typename Hash = hash<Key>, 
        typename Pred = equal_to<Key>>
class UnorderedMap : public BaseContainer
{
    friend class Iterator;

    private:
        std::shared_ptr<List<Type>[]> buckets;
        std::ptrdiff_t table_size;
        sid::ptrdiff_t capacity;
        double load_factor;
    
    public:
        using difference_type = std::ptrdiff_t;
        using reference = Type&;
        using const_reference = const Type&;
        using size_type = std::ptrdiff_t;
        using iterator = UnorderedMapIterator<Type>;
        using const_iterator = ConstUnorderedMapIterator<Type>;
        using local_iterator       = ListIterator<Type>;
        using const_local_iterator = ConstListIterator<Type>;

        using key_type             = Key;
        using mapped_type          = Type;
        using value_type           = pair<const Key, Type>;
        using hasher               = Hash;
        using key_equal            = Pred;
        using reference            = value_type&;
        using const_reference      = const value_type&;

        UnorderedMap() noexcept; // Пустой конструктор
        explicit UnorderedMap(const UnorderedMap<Type>&); // Конструктор копирования
        UnorderedMap(UnorderedMap<Type>&); // Конструктор переноса
        ~UnorderedMap();

        explicit UnorderedMap<Type>& operator =(const UnorderedMap<Type>&) // Оператор копирования
        UnorderedMap<Type>& operator=(UnorderedMap<Type>&) // Оператор переноса


        // Основные функции

        std::size_t GetSize() const noexcept override;
        bool IsEmpty() const noexcept override;
};
