//
// Created by nuelex on 16/05/25.
//

#include "FigureLPBuilder.hpp"

#include "../../../Exceptions/Builders/BuildersException.hpp"
#include "../../../Exceptions/Factory/ReaderFactoryException.hpp"
#include "../../Readers/LPReaders/LPReaderSolution.hpp"

FigureLPBuilder::FigureLPBuilder(const std::string& string) : BaseFigureLPBuilder(string), _total(0), FigureLP_(nullptr), reader_(nullptr)
{
    try
    {
        LPReaderSolution solution;
        reader_ = solution.createReader(string);

        FigureLP_ = std::make_shared<ConcreteFigureLP>();
    }
    catch (ErrorReaderFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorReaderFactory_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

bool FigureLPBuilder::buildLinks()
{
    try
    {
        FigureLP_->setLinks(reader_->readLinks());
    }
    catch (...)
    {
        return false;
    }

    _total++;

    return true;
}

bool FigureLPBuilder::buildPoints()
{
    try
    {
        FigureLP_->setPoints(reader_->readPoints());
    }
    catch (...)
    {
        return false;
    }

    _total++;

    return true;
}
