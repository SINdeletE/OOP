//
// Created by nuelex on 25/05/25.
//

#ifndef FIGURECOMMANDLOAD_HPP
#define FIGURECOMMANDLOAD_HPP
#include <functional>

#include "../BaseFigureCommand.hpp"


class FigureCommandLoad : public BaseFigureCommand
{
public:
    FigureCommandLoad(BaseObject::shared_ptr_type& object, const std::string& filename) : _object(object), _filename(filename) {}
    ~FigureCommandLoad() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override
    {
        _action = [manager](const std::string &filename) { return manager->loadObject(filename); };
    }
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    BaseObject::shared_ptr_type& _object;
    std::string _filename;
    std::function<BaseObject::shared_ptr_type(const std::string&)> _action;
};



#endif //FIGURECOMMANDLOAD_HPP
