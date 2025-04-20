#pragma once

#include <memory>
#include "concept.hpp"
#include "BaseIterator.hpp"
#include "ListIterator.hpp"
#include "Node.hpp"

template <keyType Key>
class ConstSetIterator : public BaseIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Key;
        using difference_type = std::ptrdiff_t;
        using pointer = const Key*;
        using reference =  const Key&;

        ConstSetIterator() noexcept : list_iter() {};
        ConstSetIterator(const ConstSetIterator<Key> &iter) : list_iter(iter.list_iter) {};
        ConstSetIterator(ConstSetIterator<Key> &&iter) : list_iter(std::move(iter.list_iter)) {};
        ConstSetIterator(const ListIterator<Key> &iter) : list_iter(iter) {};
        ConstSetIterator(ListIterator<Key> &&iter) : list_iter(std::move(iter)) {};
        ~ConstSetIterator() override = default;

        ConstSetIterator<Key>& operator =(const ConstSetIterator<Key> &iter) { this->list_iter = iter.list_iter; };
        ConstSetIterator<Key>& operator =(ConstSetIterator<Key> &&iter) { this->list_iter = std::move(iter.list_iter); };
        template <sizeType U> ConstSetIterator<Key>& operator +=(const U value) { list_iter += value; }

        ConstSetIterator<Key>& next();
        ConstSetIterator<Key>& operator ++();
        ConstSetIterator<Key> operator ++(int);
        difference_type operator-(const ConstSetIterator<Key>&) const;

        value_type Current();
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        auto operator <=>(const ConstSetIterator<Key> &iter) const { return this->list_iter <=> iter.list_iter; };
        bool operator ==(const ConstSetIterator<Key> &iter) const { return this->list_iter == iter.list_iter; };
        bool operator !=(const ConstSetIterator<Key> &iter) const { return this->list_iter != iter.list_iter; };

    private:
        ListIterator<Key> list_iter;
};

static_assert(std::forward_iterator<ConstSetIterator<int>>);

#include "ConstSetIterator.inl"
