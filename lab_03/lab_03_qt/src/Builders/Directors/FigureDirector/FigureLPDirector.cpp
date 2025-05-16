//
// Created by nuelex on 14/05/25.
//

#include "FigureLPDirector.hpp"

#include "../../../Exceptions/Builders/BuildersCreatorException.hpp"
#include "../../../Exceptions/Directors/DirectorException.hpp"
#include "../../Builders/FigureLPBuilder/FigureLPBuilderSolution.hpp"

FigureLPDirector::FigureLPDirector(const std::string& filename) : BaseObjectDirector(filename)
{
    FigureLPBuilderSolution solution{};

    try
    {
        _builder = solution.createBuilder(filename);
    }
    catch (ErrorBuilderCreator_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseObject> FigureLPDirector::create()
{
    if (_builder->buildPoints() && _builder->buildLinks()) return _builder->getFigureLP();

    return nullptr;
}

