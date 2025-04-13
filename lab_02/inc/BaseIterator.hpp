#pragma once

class BaseIterator
{
    public:
        // virtual void First() = 0;
        // virtual void Next() = 0;
        // virtual bool IsDone() const = 0;
        // virtual Type CurrentItem() const = 0;

        BaseIterator() = default;
        virtual ~BaseIterator() = default;
    
    protected:
        std::size_t index;
        std::size_t size;
};

