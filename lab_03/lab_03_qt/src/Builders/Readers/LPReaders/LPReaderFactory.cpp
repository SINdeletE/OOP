//
// Created by nuelex on 13/05/25.
//

#include "LPReaderFactory.hpp"

#include "../../../Exceptions/Factory/ManagerFactoryException.hpp"
#include "../../../Exceptions/Factory/ReaderFactoryException.hpp"


LPReaderFactory::LPReaderFactory() : _map()
{
    _map.max_load_factor(1.0);

    try
    {
        _map.insert({".txt", createTXTLPReader});
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReaderFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseLPReader> LPReaderFactory::createReader(const std::string& filename)
{
    auto iter = _map.find(filename);

    if (iter == _map.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReaderFactory_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second(filename);
}


