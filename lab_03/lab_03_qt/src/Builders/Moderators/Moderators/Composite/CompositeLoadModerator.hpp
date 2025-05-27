//
// Created by nuelex on 27/05/25.
//

#ifndef COMPOSITELOADMODERATOR_HPP
#define COMPOSITELOADMODERATOR_HPP
#include "../../BaseLoadModerator.hpp"
#include "../../../../BaseObject/Composite/CompositeObject.hpp"


class CompositeLoadModerator : public BaseLoadModerator
{
public:
    CompositeLoadModerator() = default;
    ~CompositeLoadModerator() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> load(const std::string& filename) override;
};



#endif //COMPOSITELOADMODERATOR_HPP
