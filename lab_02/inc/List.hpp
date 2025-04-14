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
        explicit List(const List<Type>&); // Копирование
        List(List<Type>&&); // Перенос
        // explicit List(const Node<Type>&); // Инициализация // Пока не нужен :)
        explicit List(const Type&); // Инициализация

        void push_back(const Type& value);

        // Итераторы
        iterator begin() noexcept;
        iterator end() noexcept;

        [[nodiscard]] size_type GetSize() const override;
        bool IsEmpty() const override;
};

// static_assert(ContainerConcept<List<int>>);

#include "List.inl"
