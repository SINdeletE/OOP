//
// Created by nuelex on 18/05/25.
//

#ifndef CAMERAACTIONSOLUTION_HPP
#define CAMERAACTIONSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "../ActionHash.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "../../CameraAction/CameraAction.hpp"


class CameraActionSolution
{
public:
    CameraActionSolution();
    ~CameraActionSolution() = default;

    void reg(const std::shared_ptr<BaseTransform>&, const std::shared_ptr<CameraAction>&);
    std::shared_ptr<CameraAction> createAction(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&);

private:
    std::unordered_map<std::shared_ptr<BaseTransform>, std::shared_ptr<CameraAction>, ActionHash> _actions;
};



#endif //CAMERAACTIONSOLUTION_HPP
