//
// Created by nuelex on 16/05/25.
//

#include "FigureLPBuilder.hpp"

#include "../../../Exceptions/Builders/BuildersException.hpp"
#include "../../../Exceptions/Factory/ReaderFactoryException.hpp"
#include "../../Readers/LPReaders/LPReaderSolution.hpp"

FigureLPBuilder::FigureLPBuilder(const std::string& string) : BaseFigureLPBuilder(string), _links(), _points(), FigureLP_(nullptr), reader_(nullptr)
{
    try
    {
        LPReaderSolution solution;
        reader_ = solution.createReader(string);

    }
    catch (ErrorReaderFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

bool FigureLPBuilder::buildLinks()
{
    try
    {
        _links = reader_->readLinks();
    }
    catch (...)
    {
        return false;
    }

    return true;
}

bool FigureLPBuilder::buildPoints()
{
    try
    {
        _points = reader_->readPoints();
    }
    catch (...)
    {
        return false;
    }

    return true;
}
