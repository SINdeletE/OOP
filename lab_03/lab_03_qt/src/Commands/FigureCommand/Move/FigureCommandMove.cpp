//
// Created by nuelex on 21/05/25.
//

#include "FigureCommandMove.hpp"

#include "../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"
#include "../../../Exceptions/Scene/SceneException.hpp"
#include "../../../Exceptions/Visitors/VisitorException.hpp"
#include "../../../Visitors/Transform/Move/MoveObjectVisitor.hpp"

void FigureCommandMove::execute()
{
    try
    {
        _transformManager->setParams(_sceneManager->getFigureByID(_id), _transform);
        _transformManager->request();
    }
    catch (ErrorTransformManager_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorTransformManager_invalid_transform &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorTransformManager_invalid_object &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorScene_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

