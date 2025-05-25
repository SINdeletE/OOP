//
// Created by nuelex on 25/05/25.
//

#ifndef CAMERAPTUMODERATOR_HPP
#define CAMERAPTUMODERATOR_HPP
#include "../../BaseLoadModerator.hpp"


class CameraPTUModerator : public BaseLoadModerator
{
public:
    CameraPTUModerator() = default;
    ~CameraPTUModerator() override = default;

    std::shared_ptr<BaseObject> load(const std::string &filename) override;
};



#endif //CAMERAPTUMODERATOR_HPP
