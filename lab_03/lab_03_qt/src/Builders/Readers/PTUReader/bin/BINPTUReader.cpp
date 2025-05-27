//
// Created by nuelex on 27/05/25.
//

#include "BINPTUReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"

BINPTUReader::BINPTUReader(const std::string& filename) : _instream()
{
    _instream.open(filename, std::ios::binary | std::ios::in);

    if (! _instream.is_open())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

Point BINPTUReader::readPoint()
{
    double x, y, z;

    if (this->is_open() && ! _instream.eof())
    {
        _instream.clear();
        _instream >> x >> y >> z;

        if (_instream.fail() || _instream.bad())
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    return {x, y, z};
}

Point BINPTUReader::readPosition()
{
    return readPoint();
}

Point BINPTUReader::readTarget()
{
    return readPoint();
}

Point BINPTUReader::readUp()
{
    return readPoint();
}
