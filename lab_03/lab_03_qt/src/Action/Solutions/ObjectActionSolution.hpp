//
// Created by nuelex on 17/05/25.
//

#ifndef TRANSFORMADAPTERSOLUTION_HPP
#define TRANSFORMADAPTERSOLUTION_HPP
#include <functional>
#include <memory>
#include <unordered_map>

#include "../BaseAction.hpp"
#include "BaseObjectHash.hpp"
#include "../../BaseObject/BaseObject.hpp"


class ObjectActionSolution
{
public:
    using value_type = std::function<std::shared_ptr<BaseAction>(const std::shared_ptr<BaseObject>&, \
                                                                const std::shared_ptr<BaseTransform>&)>;
    using const_reference = const value_type&;
    using key_type = std::shared_ptr<BaseObject>;

    ObjectActionSolution();
    ~ObjectActionSolution() = default;

    value_type create(const std::shared_ptr<BaseObject>& object);
    void reg(const std::shared_ptr<BaseObject> &object, const_reference lambda_ref);

private:
    std::unordered_map<key_type, value_type, BaseObjectHash> _actions;
};



#endif //TRANSFORMADAPTERSOLUTION_HPP
