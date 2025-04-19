#pragma once

#include <stdbool.h>
#include <cstddef>

#include <memory>

#include "concept.hpp"
#include "Node.hpp"
#include "ListIterator.hpp"
#include "ConstListIterator.hpp"
#include "BaseContainer.hpp"

template <keyType Type>
class List : public BaseContainer
{
    friend class ListIterator<Type>;
    friend class ConstListIterator<Type>;

    private:
        std::shared_ptr<Node<Type>> head;
    
    public:
        using difference_type = ptrdiff_t;
        using reference = Type&;
        using const_reference = const Type&;
        using value_type = Type;
        using size_type = std::ptrdiff_t;
        using iterator = ListIterator<Type>;
        using const_iterator = ConstListIterator<Type>;

        List();
        explicit List(const List<Type>&);
        List(List<Type>&&);
        // explicit List(const Node<Type>&);

        void push_back(const Type& value);
        void pop_back();
        void push_front(const Type& value);

        // Итераторы
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() noexcept;
        const_iterator cend() noexcept;

        iterator erase(iterator &pos);

        [[nodiscard]] size_type GetSize() const override;
        bool IsEmpty() const override;
};

// static_assert(ContainerConcept<List<int>>);

#include "List.inl"
