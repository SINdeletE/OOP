//
// Created by nuelex on 19/05/25.
//

#ifndef BASEVISITOR_HPP
#define BASEVISITOR_HPP
#include <memory>

class Figure;
class Camera;
class Scene;

class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual ~BaseVisitor() = default;
};



#endif //BASEVISITOR_HPP
