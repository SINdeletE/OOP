//
// Created by nuelex on 12/05/25.
//

#ifndef TRANSFORMMANAGER_HPP
#define TRANSFORMMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/BaseObject.hpp"
#include "../../Transforms/Transforms.hpp"


class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    explicit TransformManager(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform);

    void setParams(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform);

    void request();

private:
    std::shared_ptr<BaseObject> _object;
    std::shared_ptr<BaseTransform> _transform;
};



#endif //TRANSFORMMANAGER_HPP
