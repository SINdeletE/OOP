#pragma once

#include <cstddef>
#include <memory>

#include "Iterator.hpp"
#include "BaseContainer.hpp"

#include "concept.hpp"

template <numType Type>
class UnorderedMap : public BaseContainer
{
    friend class Iterator;

    private:
        std::shared_ptr<List<Type>[]> set_ptr;
        std::ptrdiff_t table_size;
        sid::ptrdiff_t capacity;
        double load_factor;
    
    public:
        using key_type             = Key;
        using mapped_type          = T;
        using value_type           = pair<const Key, T>;
        using hasher               = Hash;
        using key_equal            = Pred;
        using allocator_type       = Allocator;
        using pointer              = typename allocator_traits<Allocator>::pointer;
        using const_pointer        = typename allocator_traits<Allocator>::const_pointer;
        using reference            = value_type&;
        using const_reference      = const value_type&;
        using size_type            = /* implementation-defined */;
        using difference_type      = /* implementation-defined */;
    
        using iterator             = /* implementation-defined */;
        using const_iterator       = /* implementation-defined */;

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
