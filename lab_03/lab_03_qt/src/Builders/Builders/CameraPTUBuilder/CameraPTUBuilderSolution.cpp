//
// Created by nuelex on 16/05/25.
//

#include "CameraPTUBuilderSolution.hpp"

#include <filesystem>

#include "CameraPTUBuilder.hpp"
#include "../../../Exceptions/Builders/BuildersCreatorException.hpp"

CameraPTUBuilderSolution::CameraPTUBuilderSolution() : _map()
{
    _map.max_load_factor(1.0);

    reg({".cmr", std::make_unique<ConcreteCameraPTUBuilderCreator<CameraPTUBuilder>>()});
}

std::shared_ptr<BaseCameraPTUBuilder> CameraPTUBuilderSolution::createBuilder(const std::string& filename)
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

std::string CameraPTUBuilderSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}

void CameraPTUBuilderSolution::reg(std::pair<std::string, std::unique_ptr<CameraPTUBuilderCreator>> &&other)
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
