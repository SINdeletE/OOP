//
// Created by nuelex on 16/05/25.
//

#ifndef CAMERAPTUBUILDERSOLUTION_HPP
#define CAMERAPTUBUILDERSOLUTION_HPP
#include <memory>
#include <unordered_map>

#include "BaseCameraPTUBuilder.hpp"
#include "CameraPTUBuilderCreator.hpp"


class CameraPTUBuilderSolution
{
public:
    CameraPTUBuilderSolution();
    ~CameraPTUBuilderSolution() = default;

    std::shared_ptr<BaseCameraPTUBuilder> createBuilder(const std::string &filename);
    void reg(std::pair<std::string, std::unique_ptr<CameraPTUBuilderCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<CameraPTUBuilderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //CAMERAPTUBUILDERSOLUTION_HPP
