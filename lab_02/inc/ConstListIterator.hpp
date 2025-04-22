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
        std::ptrdiff_t index;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Type;
        using difference_type = std::ptrdiff_t;
        using pointer = const Type*;
        using reference = const Type&;

        ConstListIterator() noexcept;
        explicit ConstListIterator(const std::shared_ptr<Node<Type>> &list, const difference_type &index) noexcept;
        ConstListIterator(const ConstListIterator<Type>&) noexcept;
        ConstListIterator(ConstListIterator<Type>&&) noexcept;
        ~ConstListIterator() = default;

        ConstListIterator<Type>& operator =(const ConstListIterator<Type>&);
        ConstListIterator<Type>& operator =(ConstListIterator<Type>&&);
        template <sizeType U> ConstListIterator<Type>& operator +=(const U &value);

        ConstListIterator<Type>& next();
        ConstListIterator<Type>& operator ++();
        ConstListIterator<Type> operator ++(int);
        difference_type operator-(const ConstListIterator<Type>&) const;

        value_type Current() const;
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        bool operator ==(const ConstListIterator<Type>&) const noexcept;
        bool operator !=(const ConstListIterator<Type>&) const noexcept;

        [[nodiscard]] const std::shared_ptr<Node<Type>> GetPtr() const noexcept { return cur_ptr.lock(); }
        [[nodiscard]] difference_type GetIndex() const noexcept { return this->index; }
};

static_assert(std::forward_iterator<ConstListIterator<int>>);

#include "ConstListIterator.inl"

