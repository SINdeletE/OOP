//
// Created by nuelex on 25/05/25.
//

#ifndef FIGURELPMODERATOR_HPP
#define FIGURELPMODERATOR_HPP
#include "../../BaseLoadModerator.hpp"


class FigureLPModerator : public BaseLoadModerator
{
public:
    FigureLPModerator() = default;
    ~FigureLPModerator() override = default;

    std::shared_ptr<BaseObject> load(const std::string &filename) override;
};



#endif //FIGURELPMODERATOR_HPP
