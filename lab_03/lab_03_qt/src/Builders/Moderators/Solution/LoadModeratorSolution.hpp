//
// Created by nuelex on 25/05/25.
//

#ifndef LOADMODERATORSOLUTION_HPP
#define LOADMODERATORSOLUTION_HPP
#include <memory>
#include <string>
#include <unordered_map>

#include "LoadModeratorCreator.hpp"
#include "../BaseLoadModerator.hpp"


class LoadModeratorSolution
{
public:
    LoadModeratorSolution();
    ~LoadModeratorSolution() = default;

    std::shared_ptr<BaseLoadModerator> createLoadModerator(const std::string& filename);
    void reg(const std::string &extension, const std::shared_ptr<LoadModeratorCreator> &moderator);

private:
    std::unordered_map<std::string, std::shared_ptr<LoadModeratorCreator>> _creators;

    static std::string getExtension(const std::string &filename);
};



#endif //LOADMODERATORSOLUTION_HPP
