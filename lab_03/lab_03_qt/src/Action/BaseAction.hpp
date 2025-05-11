//
// Created by nuelex on 11/05/25.
//

#ifndef BASEACTION_HPP
#define BASEACTION_HPP



class BaseAction
{
public:
    BaseAction() = default;
    virtual ~BaseAction() = default;

    virtual void request() const = 0;
};



#endif //BASEACTION_HPP
