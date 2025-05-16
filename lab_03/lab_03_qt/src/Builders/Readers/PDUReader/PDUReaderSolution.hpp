//
// Created by nuelex on 16/05/25.
//

#ifndef PDUREADERSOLUTION_HPP
#define PDUREADERSOLUTION_HPP
#include <memory>
#include <string>
#include <unordered_map>

#include "PDUReaderCreator.hpp"


class PDUReaderSolution
{
public:
    PDUReaderSolution() = delete;
    explicit PDUReaderSolution(const std::string &filename);

    std::shared_ptr<BasePDUReader> createPDUReader();
    void reg(std::pair<std::string, std::unique_ptr<PDUReaderCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<PDUReaderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //PDUREADERSOLUTION_HPP
