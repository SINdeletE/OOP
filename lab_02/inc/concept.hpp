#pragma once

#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include <concepts>
#include <string>

template <typename T>
concept sizeType = (std::is_signed<T>::value ||
                    std::is_unsigned<T>::value) && std::is_arithmetic<T>::value;

template <typename T>
concept keyType = std::copy_constructible<T> && std::move_constructible<T> && std::default_initializable<T> && 
                std::is_copy_assignable_v<T> && std::is_move_assignable_v<T>;

template <typename T>
concept Printable_concept = requires (std::ostream& os, const T& t)
{
    { os << t } -> std::same_as<std::ostream&>;
};

template <typename T, typename U>
concept Convertible_concept = keyType<U> && (! std::same_as<T, U>) && 
                        (! std::same_as<T, U&>) && std::is_convertible_v<T, U>;



// concept HashableKey = requires(const Key& key, Hash hash, KeyEqual eq) 
// {
//     { hash(key) } -> std::convertible_to<std::ptrdiff_t>;
    
//     { eq(key, key) } -> std::convertible_to<bool>;
// };

