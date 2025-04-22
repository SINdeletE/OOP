#pragma once

#include <cstddef>
#include <stdbool.h>

class BaseContainer
{
    protected:
        std::ptrdiff_t size;
    
    public:
        virtual ~BaseContainer() = default;

        [[nodiscard]] virtual std::ptrdiff_t GetSize() const noexcept = 0;
        virtual bool IsEmpty() const noexcept = 0;
};

