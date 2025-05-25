//
// Created by nuelex on 25/05/25.
//

#ifndef FIGURECOMMANDGETBYID_HPP
#define FIGURECOMMANDGETBYID_HPP
#include <functional>

#include "../BaseFigureCommand.hpp"


class FigureCommandGetById : public BaseFigureCommand
{
public:
    FigureCommandGetById(std::shared_ptr<BaseObject>& object, size_t id) : _id(id), _object(object) {}
    ~FigureCommandGetById() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override { _action = \
                                    [manager](size_t id) { return manager->getFigureByID(id); }; }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::function<BaseObject::shared_ptr_type(size_t)> _action;

    size_t _id;
    std::shared_ptr<BaseObject>& _object;
};



#endif //FIGURECOMMANDGETBYID_HPP
