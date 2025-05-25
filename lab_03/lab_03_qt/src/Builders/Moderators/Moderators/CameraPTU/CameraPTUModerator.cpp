//
// Created by nuelex on 25/05/25.
//

#include "CameraPTUModerator.hpp"

#include "../../../../Exceptions/Moderator/ModeratorException.hpp"
#include "../../../../Exceptions/Reader/ReaderException.hpp"
#include "../../../Builders/CameraPTUBuilder/CameraPTUBuilder.hpp"
#include "../../../Directors/CameraDirector/CameraPTUDirector.hpp"
#include "../../../Readers/PTUReader/PTUReaderSolution.hpp"

std::shared_ptr<BaseObject> CameraPTUModerator::load(const std::string& filename)
{
    try
    {
        PTUReaderSolution solution{};
        auto reader = solution.createPDUReader(filename);
        auto builder = std::make_shared<CameraPTUBuilder>(reader);
        const auto director = std::make_shared<CameraPTUDirector>(builder);

        return director->create();
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorReader_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_invalid_filename(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorReader_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

