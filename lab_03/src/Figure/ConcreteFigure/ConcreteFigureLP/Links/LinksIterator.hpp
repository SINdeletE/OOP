//
// Created by nuelex on 08/05/25.
//

#ifndef LINKSITERATOR_HPP
#define LINKSITERATOR_HPP

#include <list>

template <class T, class U>
class LinksIterator
{
    typedef typename std::list<T>::iterator iterator_type;

public:
    explicit LinksIterator(U &data) : iter_data(data)
    {
        current = iter_data.links.begin();
    };
    void First()
    {
        current = iter_data.links.begin();
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

#endif //LINKSITERATOR_HPP
