//
// Created by nuelex on 16/05/25.
//

#include "PTUReaderSolution.hpp"

#include <filesystem>

#include "../../../Exceptions/Reader/ReaderException.hpp"
#include "cmr/CMRPTUReader.hpp"

void PTUReaderSolution::reg(std::pair<std::string, std::unique_ptr<PTUReaderCreator>>&& other)
{
    try
    {
        _map.emplace(std::move(other.first), std::move(other.second));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

PTUReaderSolution::PTUReaderSolution() : _map()
{
    _map.max_load_factor(1.0);

    reg({".cmr", std::make_unique<ConcretePTUReaderCreator<CMRPTUReader>>()});
}

std::string PTUReaderSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}

std::shared_ptr<BasePTUReader> PTUReaderSolution::createPDUReader(const std::string& filename)
{
    const std::string ext = getExtension(filename);
    const auto iter = _map.find(ext);

    if (iter == _map.end())
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createPDUReader(filename);
}

