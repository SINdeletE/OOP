//
// Created by nuelex on 16/05/25.
//

#include "FigureLPBuilder.hpp"

#include "../../../Exceptions/Builders/BuildersException.hpp"
#include "../../../Exceptions/Factory/ReaderFactoryException.hpp"
#include "../../Readers/LPReaders/LPReaderSolution.hpp"

FigureLPBuilder::FigureLPBuilder(const std::shared_ptr<BaseLPReader> &reader) : BaseFigureLPBuilder(reader), reader_(reader)
{
    try
    {
        FigureLP_ = std::make_shared<ConcreteFigureLP>(std::make_shared<FigureLP>());
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
        FigureLP_->figureLP_->setLinks(reader_->readLinks());
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
        FigureLP_->figureLP_->setPoints(reader_->readPoints());
    }
    catch (...)
    {
        return false;
    }

    _total++;

    return true;
}
