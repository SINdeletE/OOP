#pragma once

#include <stdbool.h>
#include <cstddef>
#include <concepts>
#include <string>

template <typename T>
concept sizeType = std::is_signed<T>::value || // std::convertible_to<std::size_t> || 
                    std::is_unsigned<T>::value || std::is_arithmetic<T>::value;

template <typename T>
concept numType = std::is_signed<T>::value || std::is_integral<T>::value ||
                    std::is_floating_point<T>::value ||
                    std::is_unsigned<T>::value || std::is_arithmetic<T>::value;

template <typename T>
concept keyType = std::is_signed<T>::value || std::is_integral<T>::value ||
                    std::is_floating_point<T>::value ||
                    std::is_unsigned<T>::value || std::is_arithmetic<T>::value ||
                    std::same_as<T, std::string>;

// concept HashableKey = requires(const Key& key, Hash hash, KeyEqual eq) 
// {
//     { hash(key) } -> std::convertible_to<std::ptrdiff_t>;
    
//     { eq(key, key) } -> std::convertible_to<bool>;
// };