//
// Created by nuelex on 08/05/25.
//

#ifndef POINTSITERATOR_HPP
#define POINTSITERATOR_HPP

#include <list>

#include "Points.hpp"

template <class T, class U>
class PointsIterator
{
    typedef typename std::list<T>::iterator iterator_type;

public:
    explicit PointsIterator(U &data) : iter_data(data)
    {
        current = iter_data.points.begin();
    };
    void First()
    {
        current = iter_data.points.begin();
    }
    void Next()
    {
        ++current;
    }
    void IsDone()
    {
        return (current == iter_data.end());
    }
    iterator_type Current()
    {
        return current;
    }

private:
    U &iter_data;
    iterator_type current;
};

#endif //POINTSITERATOR_HPP
