//
// Created by nuelex on 25/05/25.
//

#include "FigureLPModerator.hpp"

#include "../../../../Exceptions/Factory/ReaderFactoryException.hpp"
#include "../../../../Exceptions/Moderator/ModeratorException.hpp"
#include "../../../Readers/LPReaders/LPReaderSolution.hpp"
#include "../../../Builders/FigureLPBuilder/FigureLPBuilder.hpp"
#include "../../../Directors/FigureDirector/FigureLPDirector.hpp"

std::shared_ptr<BaseObject> FigureLPModerator::load(const std::string& filename)
{
    try
    {
        LPReaderSolution solution{};
        auto reader = solution.createReader(filename);
        auto builder = std::make_shared<FigureLPBuilder>(reader);
        const auto director = std::make_shared<FigureLPDirector>(builder);

        return director->create();
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorReaderFactory_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_invalid_filename(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorReaderFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

