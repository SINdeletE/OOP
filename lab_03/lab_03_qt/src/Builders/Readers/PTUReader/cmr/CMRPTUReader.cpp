//
// Created by nuelex on 16/05/25.
//

#include "CMRPTUReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"

CMRPTUReader::CMRPTUReader(const std::string& filename) : _instream()
{
    _instream.open(filename, std::ios::in);

    if (! _instream.is_open())
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

Point CMRPTUReader::readPoint()
{
    double x, y, z;

    if (this->is_open() && ! _instream.eof())
    {
        _instream.clear();
        _instream >> x >> y >> z;

        if (_instream.fail() || _instream.bad())
        {
            const time_t cur_time = time(nullptr);
            throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    return {x, y, z};
}

Point CMRPTUReader::readPosition()
{
    return readPoint();
}

Point CMRPTUReader::readTarget()
{
    return readPoint();
}

Point CMRPTUReader::readUp()
{
    return readPoint();
}
