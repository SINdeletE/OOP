//
// Created by nuelex on 20/05/25.
//

#ifndef TRANSFORMVISITORSOLUTION_HPP
#define TRANSFORMVISITORSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "BaseTransformVisitor.hpp"
#include "TransformVisitorCreator.hpp"
#include "TransformVisitorHash.hpp"


class TransformVisitorSolution
{
public:
    TransformVisitorSolution();
    ~TransformVisitorSolution() = default;

    [[nodiscard]] std::shared_ptr<BaseTransformVisitor> createVisitor(const std::shared_ptr<BaseTransform> &transform);
    void reg(const std::shared_ptr<BaseTransform> &transform, const std::shared_ptr<TransformVisitorCreator> &creator);

private:
    std::unordered_map<std::shared_ptr<BaseTransform>, std::shared_ptr<TransformVisitorCreator>, \
                       TransformVisitorHash, TransformVisitorEqual> _creators;
};



#endif //TRANSFORMVISITORSOLUTION_HPP
