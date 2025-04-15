#pragma once

#include <stdbool.h>
#include <cstddef>

#include <memory>

#include "concept.hpp"
#include "Node.hpp"
#include "ListIterator.hpp"
#include "BaseContainer.hpp"

template <numType Type>
class List : public BaseContainer
{
    friend class ListIterator<Type>;

    private:
        std::shared_ptr<Node<Type>> head;
    
    public:
        using difference_type = ptrdiff_t;
        using reference = Type&;
        using const_reference = const Type&;
        using value_type = Type;
        using size_type = std::size_t;
        using iterator = ListIterator<Type>;
        // using const_iterator = ConstListIterator<Type>;

        List();
        explicit List(const List<Type>&);
        List(List<Type>&&);
        // explicit List(const Node<Type>&);

        void push_back(const Type& value);
        void pop_back(); // Если пуст, то UB (по cppreference)

        // Итераторы
        iterator begin() noexcept;
        iterator end() noexcept;

        iterator erase(iterator &pos);

        [[nodiscard]] size_type GetSize() const override;
        bool IsEmpty() const override;
};

// static_assert(ContainerConcept<List<int>>);

#include "List.inl"
