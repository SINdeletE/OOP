//
// Created by nuelex on 14/05/25.
//

#ifndef FIGUREDIRECTOR_HPP
#define FIGUREDIRECTOR_HPP
#include <memory>
#include <string>

#include "BaseFigureLPDirector.hpp"
#include "../../Builders/FigureLPBuilder/BaseFigureLPBuilder.hpp"


class FigureLPDirector : public BaseFigureLPDirector
{
public:
    FigureLPDirector() = delete;
    explicit FigureLPDirector(const std::shared_ptr<BaseFigureLPBuilder>& builder) : BaseFigureLPDirector(builder), _builder(builder) {}
    ~FigureLPDirector() override = default;

    [[nodiscard]] std::shared_ptr<BaseObject> create() override;

private:
    std::shared_ptr<BaseFigureLPBuilder> _builder;
};



#endif //FIGUREDIRECTOR_HPP
