//
// Created by nuelex on 19/05/25.
//

#ifndef BASEVISITOR_HPP
#define BASEVISITOR_HPP
#include <memory>

class Figure;
class Camera;
class Scene;

class BaseDrawTemplateVisitor
{
public:
    BaseDrawTemplateVisitor() = default;
    virtual ~BaseDrawTemplateVisitor() = default;
};



#endif //BASEVISITOR_HPP
