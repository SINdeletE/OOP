//
// Created by nuelex on 13/05/25.
//

#ifndef LPREADERFACTORY_HPP
#define LPREADERFACTORY_HPP
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "BaseLPReader.hpp"
#include "../../../Factory/BaseFactory.hpp"
#include "txt/TXTLPReader.hpp"

class LPReaderFactory : public BaseFactory
{
public:
    LPReaderFactory();
    ~LPReaderFactory() override = default;

    std::shared_ptr<BaseLPReader> createReader(const std::string &filename);
    static std::shared_ptr<BaseLPReader> createTXTLPReader(const std::string &filename) { return std::make_shared<TXTLPReader>(filename); }

private:
    std::unordered_map<std::string, std::function<std::shared_ptr<BaseLPReader>(const std::string &)>> _map;
};



#endif //LPREADERFACTORY_HPP
