#pragma once

#include <cstddef>
#include <concepts>

template <typename T>
concept sizeType = std::is_signed<T>::value || // std::convertible_to<std::size_t> || 
                    std::is_unsigned<T>::value || std::is_arithmetic<T>::value;

template <typename T>
concept numType = std::is_signed<T>::value || std::is_integral<T>::value ||
                    std::is_floating_point<T>::value ||
                    std::is_unsigned<T>::value || std::is_arithmetic<T>::value; 
                    