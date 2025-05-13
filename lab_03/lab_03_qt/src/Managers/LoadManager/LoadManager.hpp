//
// Created by nuelex on 12/05/25.
//

#ifndef LOADMANAGER_HPP
#define LOADMANAGER_HPP
#include "../BaseManager.hpp"


class LoadManager final: public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() override = default;

    void execute();

private:

};



#endif //LOADMANAGER_HPP
