#pragma once

#include <cstddef>
#include <stdbool.h>

class BaseContainer
{
    private:
        std::size_t size;
    
    public:
        virtual ~BaseContainer() = default;

        virtual std::size_t GetSize() const = 0;
        virtual bool IsEmpty() const = 0;
};

