//
// Created by nuelex on 27/05/25.
//

#include "CompositeLoadModerator.hpp"

#include <iostream>

#include "../../../../Exceptions/Moderator/ModeratorException.hpp"
#include "../../../../Exceptions/Reader/ReaderException.hpp"
#include "../../../Readers/ArchiveReaders/BaseArchiveReader.hpp"
#include "../../../Readers/ArchiveReaders/targz/TARGZReader.hpp"
#include "../../Solution/LoadModeratorSolution.hpp"

std::shared_ptr<BaseObject> CompositeLoadModerator::load(const std::string& filename)
{
    try
    {
        LoadModeratorSolution solution{};
        std::shared_ptr<BaseArchiveReader> reader = std::make_shared<TARGZReader>(filename);

        std::string name{};
        std::shared_ptr<BaseLoadModerator> moderator{nullptr};

        std::shared_ptr<BaseObject> result = std::make_shared<CompositeObject>();
        for (std::shared_ptr<BaseArchiveReader> reader = std::make_shared<TARGZReader>(filename); ! reader->isEnd(); reader->next())
        {
            name = reader->current();
            moderator = solution.createLoadModerator(name);

            result->addChild(moderator->load(reader->current()));
        }

        return result;
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorModerator_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_archive(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}
