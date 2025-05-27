//
// Created by nuelex on 25/05/25.
//

#include "LoadModeratorSolution.hpp"

#include <filesystem>

#include "LoadModeratorCreator.hpp"
#include "../../../Exceptions/Moderator/ModeratorException.hpp"
#include "../Moderators/CameraPTU/CameraPTUModerator.hpp"
#include "../Moderators/FigureLP/FigureLPModerator.hpp"


LoadModeratorSolution::LoadModeratorSolution()
{
    try
    {
        this->reg(".txt", std::make_shared<ConcreteLoadModeratorCreator<FigureLPModerator>>());
        this->reg(".csv", std::make_shared<ConcreteLoadModeratorCreator<FigureLPModerator>>());
        this->reg(".bin", std::make_shared<ConcreteLoadModeratorCreator<FigureLPModerator>>());

        this->reg(".cmr", std::make_shared<ConcreteLoadModeratorCreator<CameraPTUModerator>>());
        this->reg(".csvcmr", std::make_shared<ConcreteLoadModeratorCreator<CameraPTUModerator>>());
        this->reg(".bincmr", std::make_shared<ConcreteLoadModeratorCreator<CameraPTUModerator>>());
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void LoadModeratorSolution::reg(const std::string& extension, const std::shared_ptr<LoadModeratorCreator>& creator)
{
    _creators[extension] = creator;
}

std::shared_ptr<BaseLoadModerator> LoadModeratorSolution::createLoadModerator(const std::string &filename)
{
    auto iter = _creators.find(getExtension(filename));

    if (iter == _creators.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_invalid_filename(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createLoadModerator();
}

std::string LoadModeratorSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}



