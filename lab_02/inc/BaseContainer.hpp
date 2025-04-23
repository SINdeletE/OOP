#pragma once

#include <cstddef>
#include <stdbool.h>

class BaseContainer
{
    public:
        using size_type = std::ptrdiff_t;

        virtual ~BaseContainer() = default;

        [[nodiscard]] virtual size_type size() const noexcept = 0;
        virtual bool IsEmpty() const noexcept = 0;

    protected:
        size_type _size;
    
};

