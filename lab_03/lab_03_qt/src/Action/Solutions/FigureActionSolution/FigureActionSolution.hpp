//
// Created by nuelex on 18/05/25.
//

#ifndef FIGUREACTIONSOLUTION_HPP
#define FIGUREACTIONSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "../ActionHash.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "../../FigureAction/FigureAction.hpp"


class FigureActionSolution
{
public:
    FigureActionSolution();
    ~FigureActionSolution() = default;

    void reg(const std::shared_ptr<BaseTransform>&, const std::shared_ptr<FigureAction>&);
    std::shared_ptr<FigureAction> createAction(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&);

private:
    std::unordered_map<std::shared_ptr<BaseTransform>, std::shared_ptr<FigureAction>, ActionHash> _actions;
};



#endif //FIGUREACTIONSOLUTION_HPP
