//
// Created by nuelex on 13/05/25.
//

#include "LPReaderSolution.hpp"

#include <filesystem>

#include "../../../Exceptions/Factory/ManagerFactoryException.hpp"
#include "../../../Exceptions/Factory/ReaderFactoryException.hpp"


LPReaderSolution::LPReaderSolution() : _map()
{
    _map.max_load_factor(1.0);

    try
    {
        _map.insert({".txt", std::make_unique<ConcreteLPReaderCreator<TXTLPReader>>()});
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReaderFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseLPReader> LPReaderSolution::createReader(const std::string& filename)
{
    const std::string ext = getExtension(filename);
    const auto iter = _map.find(ext);

    if (iter == _map.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReaderFactory_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createLPReader(filename);
}

std::string LPReaderSolution::getExtension(const std::string& filename)
{
    const auto ext = std::filesystem::path(filename).extension();

    return ext.string();
}


