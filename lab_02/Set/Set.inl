// #include "set.hpp"

std::size_t Set::GetSize() const noexcept override
{
    return size;
}

bool Set::IsEmpty() const noexcept override
{
    return size == 0;
}