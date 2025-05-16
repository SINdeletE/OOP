//
// Created by nuelex on 14/05/25.
//

#ifndef MAINDIRECTOR_HPP
#define MAINDIRECTOR_HPP
#include <memory>
#include <string>
#include <unordered_map>

#include "BaseDirector.hpp"
#include "DirectorCreator.hpp"


class DirectorSolution
{
public:
    DirectorSolution();
    ~DirectorSolution() = default;

    std::shared_ptr<BaseDirector> createDirector(const std::string& filename);
    void reg(std::pair<std::string, std::unique_ptr<DirectorCreator>> &&other);

private:
    std::unordered_map<std::string, std::unique_ptr<DirectorCreator>> _directorCreators;

    static std::string getExtension(const std::string &filename);
};



#endif //MAINDIRECTOR_HPP
