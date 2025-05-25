//
// Created by nuelex on 25/05/25.
//

#ifndef BASEFIGURELPDIRECTOR_HPP
#define BASEFIGURELPDIRECTOR_HPP
#include <memory>

#include "../../Builders/FigureLPBuilder/BaseFigureLPBuilder.hpp"


class BaseFigureLPDirector
{
public:
    explicit BaseFigureLPDirector(const std::shared_ptr<BaseFigureLPBuilder> builder) {};
    virtual ~BaseFigureLPDirector() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseObject> create() = 0;
};



#endif //BASEFIGURELPDIRECTOR_HPP
