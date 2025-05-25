//
// Created by nuelex on 13/05/25.
//

#ifndef LPREADERFACTORY_HPP
#define LPREADERFACTORY_HPP
#include <memory>
#include <string>
#include <unordered_map>

#include "BaseLPReader.hpp"
#include "LPReaderCreator.hpp"

class LPReaderSolution
{
public:
    LPReaderSolution();
    ~LPReaderSolution() = default;

    std::shared_ptr<BaseLPReader> createReader(const std::string &filename);
    void reg(std::pair<std::string, std::unique_ptr<LPReaderCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<LPReaderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //LPREADERFACTORY_HPP
