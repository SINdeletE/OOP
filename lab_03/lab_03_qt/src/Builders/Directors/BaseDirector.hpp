//
// Created by nuelex on 13/05/25.
//

#ifndef BASEDIRECTOR_HPP
#define BASEDIRECTOR_HPP



class BaseDirector
{
public:
    explicit BaseDirector(const std::string &filename) {}
    virtual ~BaseDirector() = default;

    virtual void create() = 0;
};



#endif //BASEDIRECTOR_HPP
