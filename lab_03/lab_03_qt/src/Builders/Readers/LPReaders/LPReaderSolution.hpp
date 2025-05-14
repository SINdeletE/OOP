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
#include "LPReaderCreator.hpp"
#include "../../../Factory/BaseFactory.hpp"
#include "txt/TXTLPReader.hpp"

class LPReaderSolution : public BaseFactory
{
public:
    LPReaderSolution();
    ~LPReaderSolution() override = default;

    std::shared_ptr<BaseLPReader> createReader(const std::string &filename);

private:
    std::unordered_map<std::string, std::unique_ptr<LPReaderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //LPREADERFACTORY_HPP
