#pragma once

#include <stdbool.h>
#include <cstddef>
#include <memory>

#include "concept.hpp"
#include "Node.hpp"
#include "BaseContainer.hpp"
#include "ListIterator.hpp"

template <numType Type>
class List : public BaseContainer
{
    friend class ListIterator<Type>;

    private:
        std::shared_ptr<Node<Type>> head;
    
    public:
        List();
        explicit List(const Type&);

        

        std::size_t GetSize() const override;
        bool IsEmpty() const override;
};

#include "List.inl"
