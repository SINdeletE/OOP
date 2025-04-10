#pragma once

#include <cstddef>
#include <cstdbool>

#include "iterator.hpp"


class BaseSet
{
    private:
        std::size_t size;
    
    public:
        BaseSet();
        virtual ~BaseSet() = default;

        virtual std::size_t GetSize() const = 0;
        virtual bool IsEmpty() const = 0;
};

