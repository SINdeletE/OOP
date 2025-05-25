//
// Created by nuelex on 16/05/25.
//

#include "CameraPTUBuilder.hpp"

#include "../../../Exceptions/Builders/BuildersException.hpp"
#include "../../../Exceptions/Reader/ReaderException.hpp"
#include "../../Readers/PTUReader/PTUReaderSolution.hpp"

CameraPTUBuilder::CameraPTUBuilder(const std::shared_ptr<BasePTUReader> &reader) : BaseCameraPTUBuilder(reader), _camera(nullptr), \
                                                                  _reader(reader)
{
    try
    {
        _camera = std::make_shared<CameraPTU>();
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorBuilder_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

bool CameraPTUBuilder::buildPosition()
{
    try
    {
        _camera->setPosition(_reader->readPosition());
    }
    catch (ErrorReader_invalid_file &e)
    {
        return false;
    }

    _total++;

    return true;
}

bool CameraPTUBuilder::buildTarget()
{
    try
    {
        _camera->setTarget(_reader->readTarget());
    }
    catch (ErrorReader_invalid_file &e)
    {
        return false;
    }

    _total++;

    return true;
}

bool CameraPTUBuilder::buildUp()
{
    try
    {
        _camera->setUp(_reader->readUp());
    }
    catch (ErrorReader_invalid_file &e)
    {
        return false;
    }

    _total++;

    return true;
}
