//
// Created by nuelex on 20/05/25.
//

#ifndef TRANSFORMVISITORHASH_HPP
#define TRANSFORMVISITORHASH_HPP
#include "BaseTransformVisitor.hpp"


class TransformVisitorHash
{
public:
    TransformVisitorHash() = default;
    ~TransformVisitorHash() = default;

    std::size_t operator()(const std::shared_ptr<BaseTransform> &visitor) const
    {
        return typeid(*visitor).hash_code();
    }
};

class TransformVisitorEqual
{
public:
    TransformVisitorEqual() = default;
    ~TransformVisitorEqual() = default;

    bool operator()(const std::shared_ptr<BaseTransform> &transform1, const std::shared_ptr<BaseTransform> &transform2) const
    {
        return typeid(*transform1).hash_code() == typeid(*transform2).hash_code();
    }
};



#endif //TRANSFORMVISITORHASH_HPP
