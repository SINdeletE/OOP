//
// Created by nuelex on 14/05/25.
//

#include "DirectorSolution.hpp"

#include <filesystem>

#include "../../Exceptions/Directors/DirectorException.hpp"
#include "FigureDirector/FigureLPDirector.hpp"

DirectorSolution::DirectorSolution() : _directorCreators()
{
    _directorCreators.max_load_factor(1.0);

    reg({".txt", std::make_unique<ConcreteDirectorCreator<FigureLPDirector>>()});
}

std::shared_ptr<BaseObjectDirector> DirectorSolution::createDirector(const std::string& filename)
{
    const std::string ext = getExtension(filename);
    const auto iter = _directorCreators.find(ext);

    if (iter == _directorCreators.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createDirector(filename);
}

std::string DirectorSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}

void DirectorSolution::reg(std::pair<std::string, std::unique_ptr<DirectorCreator>> &&other)
{
    try
    {
        _directorCreators.emplace(std::move(other.first), std::move(other.second));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}


