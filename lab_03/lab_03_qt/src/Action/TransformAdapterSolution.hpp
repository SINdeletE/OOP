//
// Created by nuelex on 17/05/25.
//

#ifndef TRANSFORMADAPTERSOLUTION_HPP
#define TRANSFORMADAPTERSOLUTION_HPP
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "BaseAction.hpp"
#include "../BaseObject/BaseObject.hpp"


class TransformAdapterSolution
{
public:
    TransformAdapterSolution();
    ~TransformAdapterSolution() = default;

    std::shared_ptr<BaseAction> createAction(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform);
    void reg(std::shared_ptr<BaseTransform> &transform);

private:
    std::unordered_map<std::type_index,
                        std::function<std::shared_ptr<BaseAction>(const std::shared_ptr<BaseObject> &object,
                                                                const std::shared_ptr<BaseTransform> &transform)>> _actions;
};



#endif //TRANSFORMADAPTERSOLUTION_HPP
