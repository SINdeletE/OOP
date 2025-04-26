#pragma once

#include <stdbool.h>
#include <cstddef>

#include <memory>

#include "concept.hpp"
#include "Node.hpp"
#include "ConstListIterator.hpp"
#include "BaseContainer.hpp"
#include "ListException.hpp"

template <keyType Type>
class List : public BaseContainer
{
    friend class ConstListIterator<Type>;
    
    public:
        using difference_type = ptrdiff_t;
        using reference = Type&;
        using const_reference = const Type&;
        using value_type = Type;
        using size_type = std::ptrdiff_t;
        using iterator = ConstListIterator<Type>;
        using const_iterator = ConstListIterator<Type>;

        List() noexcept;
        explicit List(const List<Type>&);
        List(List<Type>&&) noexcept;

        List<Type>& operator =(const List<Type>&);
        List<Type>& operator =(List<Type>&&) noexcept;

        const_iterator push_back(const Type& value);
        void pop_back();
        void push_front(const Type& value);
        const_iterator insert(const_iterator &pos, const Type& value);

        // Итераторы
        iterator begin() const noexcept;
        iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        const_iterator erase(const_iterator &pos);

        [[nodiscard]] size_type size() const noexcept override;
        bool IsEmpty() const noexcept override;
    
    private:
        std::shared_ptr<Node<Type>> head;

        const_iterator prev_iter(const const_iterator &iter);
};

static_assert(Container_concept<List<int>>);

template <keyType Type>
requires Printable_concept<Type>
std::ostream& operator <<(std::ostream &os, List<Type> &list)
{
    for (auto &v : list)
        os << v << ' ';

    os << std::endl;

    return os;
}

#include "List.inl"
