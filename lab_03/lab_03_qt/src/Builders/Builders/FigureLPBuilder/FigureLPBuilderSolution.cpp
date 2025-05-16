//
// Created by nuelex on 16/05/25.
//

#include "FigureLPBuilderSolution.hpp"

#include <filesystem>

#include "FigureLPBuilder.hpp"
#include "../../../Exceptions/Builders/BuildersCreatorException.hpp"

FigureLPBuilderSolution::FigureLPBuilderSolution() : _map()
{
    _map.max_load_factor(1.0);

    reg({".txt", std::make_unique<ConcreteLPBuilderCreator<FigureLPBuilder>>()});
}

std::shared_ptr<BaseFigureLPBuilder> FigureLPBuilderSolution::createBuilder(const std::string& filename)
{
    const std::string ext = getExtension(filename);
    const auto iter = _map.find(ext);

    if (iter == _map.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilderCreator_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createFigureLPBuilder(filename);
}

std::string FigureLPBuilderSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}

void FigureLPBuilderSolution::reg(std::pair<std::string, std::unique_ptr<FigureLPBuilderCreator>> &&other)
{
    try
    {
        _map.emplace(std::move(other.first), std::move(other.second));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilderCreator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}
