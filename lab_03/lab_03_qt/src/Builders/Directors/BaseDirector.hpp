//
// Created by nuelex on 13/05/25.
//

#ifndef BASEDIRECTOR_HPP
#define BASEDIRECTOR_HPP



class BaseDirector
{
public:
    BaseDirector() = default;
    virtual ~BaseDirector() = default;

    virtual void create() = 0;
};



#endif //BASEDIRECTOR_HPP
