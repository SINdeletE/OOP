//
// Created by nuelex on 20/05/25.
//

#ifndef DRAWVISITORSOLUTION_HPP
#define DRAWVISITORSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "DrawVisitorCreator.hpp"
#include "DrawVisitorHash.hpp"
#include "../../../BaseObject/BaseObject.hpp"


class DrawVisitorSolution
{
public:
    DrawVisitorSolution();
    ~DrawVisitorSolution() = default;

    std::shared_ptr<BaseDrawTemplateVisitor> createDrawTemplateVisitor(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<Camera> &camera, \
                                                                       const std::shared_ptr<BaseDrawer> &drawer);
    void reg(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<DrawVisitorCreator> &creator);

private:
    std::unordered_map<std::shared_ptr<BaseObject>, std::shared_ptr<DrawVisitorCreator>, \
                       DrawVisitorHash, DrawVisitorEqual> _creators;
};



#endif //DRAWVISITORSOLUTION_HPP
