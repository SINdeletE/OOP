#pragma once

#include <cstddef>
#include <stdbool.h>

#include <memory>
#include <ranges>
#include <iterator>

#include "Node.hpp"
#include "BaseIterator.hpp"
#include "concept.hpp"

template <keyType Type>
class ConstListIterator : public BaseIterator
{
    private:
        std::weak_ptr<Node<Type>> cur_ptr;
        std::ptrdiff_t index;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Type;
        using difference_type = std::ptrdiff_t;
        using pointer = const Type*;
        using reference = const Type&;

        ConstListIterator() noexcept;
        explicit ConstListIterator(const std::shared_ptr<Node<Type>> &list, const difference_type &index);
        ConstListIterator(const ConstListIterator<Type>&);
        ConstListIterator(ConstListIterator<Type>&&);
        ConstListIterator(int size) = delete;
        ~ConstListIterator() = default;

        ConstListIterator<Type>& operator =(const ConstListIterator<Type>&);
        ConstListIterator<Type>& operator =(ConstListIterator<Type>&&);
        template <sizeType U> ConstListIterator<Type>& operator +=(const U value);

        ConstListIterator<Type>& next();
        ConstListIterator<Type>& operator ++();
        ConstListIterator<Type> operator ++(int);
        difference_type operator-(const ConstListIterator<Type>&);

        value_type Current();
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        auto operator <=>(const ConstListIterator<Type>&) const;
        bool operator ==(const ConstListIterator<Type>&) const;
        bool operator !=(const ConstListIterator<Type>&) const;

        const std::shared_ptr<Node<Type>> GetPtr() { return cur_ptr.lock(); };
};

static_assert(std::forward_iterator<ConstListIterator<int>>);

#include "ConstListIterator.inl"

