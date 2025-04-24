#pragma once

#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include <concepts>
#include <ranges>
#include <string>

// sizeType concepts

template <typename T>
concept sizeType = (std::is_signed<T>::value ||
                    std::is_unsigned<T>::value) && std::is_arithmetic<T>::value;

// Types concepts

template <typename T>
concept copyType = std::copy_constructible<T> && std::is_copy_assignable_v<T>;

template <typename T>
concept keyType = copyType<T> && std::move_constructible<T> && 
                std::default_initializable<T> && std::is_move_assignable_v<T>;

// Container concepts

template <typename T>
concept copy_construct = std::constructible_from<T, T&> && std::constructible_from<T, const T&> && std::constructible_from<T, const T>;

template <typename T>
concept base_container_attributes = requires (T t)
{
    typename T::value_type;
    typename T::size_type;
    typename T::iterator;
    typename T::const_iterator;

    { t.size() } noexcept -> std::same_as<typename T::size_type>;
    { t.cbegin() } noexcept -> std::same_as<typename T::const_iterator>;
    { t.cend() } noexcept -> std::same_as<typename T::const_iterator>;
};

template <typename T>
concept Container_concept = copy_construct<T> && std::move_constructible<T> && std::default_initializable<T> && 
                            std::is_copy_assignable_v<T> && std::is_move_assignable_v<T> && base_container_attributes<T>;

// range concept

template <typename T>
concept Range_concept = std::ranges::forward_range<T>;


// able/ible concepts

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

