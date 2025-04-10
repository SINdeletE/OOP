#pragma once

#include <cstddef>

#include "iterator.hpp"


class BaseSet
{
    private:
        std::size_t size;
    
    public:
        BaseSet();
        virtual ~BaseSet() = default;

        virtual size_t GetSize() const = 0;
};

