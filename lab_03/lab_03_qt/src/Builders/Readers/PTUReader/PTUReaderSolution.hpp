//
// Created by nuelex on 16/05/25.
//

#ifndef PDUREADERSOLUTION_HPP
#define PDUREADERSOLUTION_HPP
#include <memory>
#include <string>
#include <unordered_map>

#include "PTUReaderCreator.hpp"

class PTUReaderSolution
{
public:
    PTUReaderSolution();
    ~PTUReaderSolution() = default;

    std::shared_ptr<BasePTUReader> createPDUReader(const std::string& filename);
    void reg(std::pair<std::string, std::unique_ptr<PTUReaderCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<PTUReaderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //PDUREADERSOLUTION_HPP
