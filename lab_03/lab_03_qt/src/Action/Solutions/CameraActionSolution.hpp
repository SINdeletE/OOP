//
// Created by nuelex on 18/05/25.
//

#ifndef CAMERAACTIONSOLUTION_HPP
#define CAMERAACTIONSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "../../Transforms/Transforms.hpp"
#include "../CameraAction/CameraAction.hpp"


class CameraActionSolution
{


private:
    std::unordered_map<std::shared_ptr<BaseTransform>, std::shared_ptr<CameraAction>>
};



#endif //CAMERAACTIONSOLUTION_HPP
