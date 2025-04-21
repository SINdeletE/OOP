#pragma once

#include <memory>
#include "concept.hpp"
#include "BaseIterator.hpp"
#include "ListIterator.hpp"
#include "Node.hpp"

template <keyType Key>
class SetIterator : public BaseIterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Key;
        using difference_type = std::ptrdiff_t;
        using pointer = Key*;
        using reference = Key&;

        SetIterator() noexcept : list_iter() {};
        SetIterator(const SetIterator<Key> &iter) : list_iter(iter.list_iter) {};
        SetIterator(SetIterator<Key> &&iter) : list_iter(std::move(iter.list_iter)) {};
        SetIterator(const ListIterator<Key> &iter) : list_iter(iter) {};
        SetIterator(ListIterator<Key> &&iter) : list_iter(std::move(iter)) {};
        ~SetIterator() override = default;

        SetIterator<Key>& operator =(const SetIterator<Key> &iter) { this->list_iter = iter.list_iter; return *this; };
        SetIterator<Key>& operator =(SetIterator<Key> &&iter) { this->list_iter = std::move(iter.list_iter); return *this; };
        template <sizeType U> SetIterator<Key>& operator +=(const U value) { list_iter += value; }

        SetIterator<Key>& next();
        SetIterator<Key>& operator ++();
        SetIterator<Key> operator ++(int);
        difference_type operator-(const SetIterator<Key>&) const;

        value_type Current();
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        auto operator <=>(const SetIterator<Key> &iter) const { return this->list_iter <=> iter.list_iter; };
        bool operator ==(const SetIterator<Key> &iter) const { return this->list_iter == iter.list_iter; };
        bool operator !=(const SetIterator<Key> &iter) const { return this->list_iter != iter.list_iter; };

    private:
        ListIterator<Key> list_iter;
};

static_assert(std::forward_iterator<SetIterator<int>>);

#include "SetIterator.inl"
