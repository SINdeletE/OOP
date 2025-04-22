#pragma once

#include <cstddef>
#include <stdbool.h>

class BaseContainer
{
    protected:
        std::ptrdiff_t size;
    
    public:
        using size_type = std::ptrdiff_t;

        virtual ~BaseContainer() = default;

        [[nodiscard]] virtual size_type GetSize() const noexcept = 0;
        virtual bool IsEmpty() const noexcept = 0;
};

