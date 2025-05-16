//
// Created by nuelex on 16/05/25.
//

#ifndef FIGURELPBUILDERSOLUTION_HPP
#define FIGURELPBUILDERSOLUTION_HPP
#include <unordered_map>

#include "BaseFigureLPBuilder.hpp"
#include "FigureLPBuilderCreator.hpp"


class FigureLPBuilderSolution
{
public:
    FigureLPBuilderSolution();
    ~FigureLPBuilderSolution() = default;

    std::shared_ptr<BaseFigureLPBuilder> createBuilder(const std::string &filename);
    void reg(std::pair<std::string, std::unique_ptr<FigureLPBuilderCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<FigureLPBuilderCreator>> _map;

    static std::string getExtension(const std::string &filename);
};



#endif //FIGURELPBUILDERSOLUTION_HPP
