//
// Created by nuelex on 25/05/25.
//

#ifndef TRANSFORMMANAGERCOMMANDSETPARAMS_HPP
#define TRANSFORMMANAGERCOMMANDSETPARAMS_HPP
#include <functional>

#include "../BaseTransformManagerCommand.hpp"


class TransformManagerCommandSetParams : public BaseTransformManagerCommand
{
public:
    TransformManagerCommandSetParams(BaseObject::shared_ptr_type& object, const std::shared_ptr<BaseTransform>& transform) : _object(object), _transform(transform) {}
    ~TransformManagerCommandSetParams() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override
    {
        _action = [manager](const BaseObject::shared_ptr_type& object, const std::shared_ptr<BaseTransform>& transform)
        {
            manager->setParams(object, transform);
        };
    }

    void execute() override;

private:
    BaseObject::shared_ptr_type& _object;
    std::shared_ptr<BaseTransform> _transform;
    std::function<void(const BaseObject::shared_ptr_type&, const std::shared_ptr<BaseTransform>&)> _action;
};



#endif //TRANSFORMMANAGERCOMMANDSETPARAMS_HPP
