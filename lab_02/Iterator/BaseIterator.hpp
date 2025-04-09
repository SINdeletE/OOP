#pragma once

template <class Type>
class BaseIterator
{
    public:
        // virtual void First() = 0;
        // virtual void Next() = 0;
        // virtual bool IsDone() const = 0;
        // virtual Type CurrentItem() const = 0;

        BaseIterator();
        virtual ~BaseIterator() = default;
    
    protected:
        size_t index;
        size_t size;
};

