#pragma once

#include <cstddef>
#include <stdbool.h>

#include <memory>
#include <ranges>
#include <iterator>

#include "Node.hpp"
#include "BaseIterator.hpp"
#include "ListException.hpp"
#include "concept.hpp"

template <keyType Type>
class ConstListIterator : public BaseIterator
{
    private:
        std::weak_ptr<Node<Type>> cur_ptr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Type;
        using difference_type = std::ptrdiff_t;
        using pointer = const Type*;
        using reference = const Type&;

        ConstListIterator() noexcept;
        explicit ConstListIterator(const std::shared_ptr<Node<Type>> &list) noexcept;
        ConstListIterator(const ConstListIterator<Type>&) noexcept;
        ConstListIterator(ConstListIterator<Type>&&) noexcept;
        ~ConstListIterator() = default;

        ConstListIterator<Type>& operator =(const ConstListIterator<Type>&) noexcept;
        ConstListIterator<Type>& operator =(ConstListIterator<Type>&&) noexcept;
        template <sizeType U> ConstListIterator<Type>& operator +=(const U &value);

        ConstListIterator<Type>& next() noexcept;
        ConstListIterator<Type>& operator ++();
        ConstListIterator<Type> operator ++(int);
        template <sizeType U> ConstListIterator<Type> operator +(const U &offset) const noexcept;

        value_type Current() const;
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        bool operator ==(const ConstListIterator<Type>&) const noexcept;
        bool operator !=(const ConstListIterator<Type>&) const noexcept;

        [[nodiscard]] const std::shared_ptr<Node<Type>> GetPtr() const noexcept { return cur_ptr.lock(); }
};

static_assert(std::forward_iterator<ConstListIterator<int>>);

#include "ConstListIterator.inl"

