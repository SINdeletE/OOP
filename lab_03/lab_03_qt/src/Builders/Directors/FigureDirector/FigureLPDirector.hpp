//
// Created by nuelex on 14/05/25.
//

#ifndef FIGUREDIRECTOR_HPP
#define FIGUREDIRECTOR_HPP
#include <memory>
#include <string>

#include "../BaseDirector.hpp"
#include "../../Builders/FigureLPBuilder/BaseFigureLPBuilder.hpp"


class FigureLPDirector : public BaseDirector
{
public:
    FigureLPDirector() = delete;
    explicit FigureLPDirector(const std::string &filename);
    ~FigureLPDirector() override = default;

    void create() override {}

private:
    std::shared_ptr<BaseFigureLPBuilder> _builder;
};



#endif //FIGUREDIRECTOR_HPP
