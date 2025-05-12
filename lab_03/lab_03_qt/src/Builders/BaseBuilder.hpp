//
// Created by nuelex on 12/05/25.
//

#ifndef BASEBUILDER_HPP
#define BASEBUILDER_HPP

#include <cstdbool>

class BaseBuilder
{
protected:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual bool isBuilded() = 0;
    virtual void reset() = 0;
};



#endif //BASEBUILDER_HPP
