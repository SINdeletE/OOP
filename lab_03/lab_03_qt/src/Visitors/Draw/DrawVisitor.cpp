//
// Created by nuelex on 20/05/25.
//

#include "DrawVisitor.hpp"

#include "../../Managers/SceneManager/Scene/Scene/Scene.hpp"
#include "Solution/DrawVisitorSolution.hpp"

void DrawVisitor::visitScene(const Scene& scene)
{
    auto composite = scene.getCompositeObject();
    DrawVisitorSolution solution{};

    for (auto it = composite.begin(); it != composite.end(); ++it)
    {
        auto object = *it;
        object->accept(*solution.createDrawTemplateVisitor(object, _drawer));
    }
}

