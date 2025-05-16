//
// Created by nuelex on 16/05/25.
//

#include "CameraPTUDirector.hpp"

#include "../../../Exceptions/Builders/BuildersCreatorException.hpp"
#include "../../../Exceptions/Directors/DirectorException.hpp"
#include "../../Builders/CameraPTUBuilder/CameraPTUBuilderSolution.hpp"

CameraPTUDirector::CameraPTUDirector(const std::string& filename) : BaseObjectDirector(filename)
{
    try
    {
        CameraPTUBuilderSolution solution;
        _builder = solution.createBuilder(filename);
    }
    catch (ErrorBuilderCreator_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorBuilderCreator_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDirector_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseObject> CameraPTUDirector::create()
{
    if (_builder->buildPosition() && _builder->buildTarget() && _builder->buildUp())
        return _builder->getCameraPTU();

    return nullptr;
}

