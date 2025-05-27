//
// Created by nuelex on 27/05/25.
//

#include "BINLPReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"

BINLPReader::BINLPReader(const std::string& filename) : _sizePoints(0), _sizeLinks(0)
{
    _instream.open(filename, std::ios::binary | std::ios::in);

    if (! _instream.is_open())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

Link BINLPReader::readLink()
{
    uint64_t BeginID = 0, EndID = 0;

    if (this->is_open() && ! _instream.eof())
    {
        _instream.clear();
        _instream >> BeginID >> EndID;

        if (_instream.fail() || _instream.bad())
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    if (BeginID == EndID || BeginID >= _sizePoints || EndID >= _sizePoints)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return {static_cast<std::size_t>(BeginID), static_cast<std::size_t>(EndID)};
}

Point BINLPReader::readPoint()
{
    double x = 0, y = 0, z = 0;

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

bool BINLPReader::linkIsCorrect(Links &links, const Link &link)
{
    bool flag = true;
    LinksIterator<Link, Links> iterator(links);

    for (iterator.First(); flag && ! iterator.IsDone(); iterator.Next())
        if ((link.GetBeginID() == iterator.Current()->GetBeginID() && \
            link.GetEndID() == iterator.Current()->GetEndID()) ||
            (link.GetBeginID() == iterator.Current()->GetEndID() && \
            link.GetEndID() == iterator.Current()->GetBeginID()))
            flag = false;

    return flag;
}

Links BINLPReader::readLinks()
{
    Links links{};
    Link link{};

    readSizeLinks();
    for (std::size_t i = 0; i < _sizeLinks; i++)
    {
        link = readLink();
        if (! linkIsCorrect(links, link))
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        links.AddLink(link);
    }

    return links;
}

Points BINLPReader::readPoints()
{
    Points points{};
    Point point{};

    readSizePoints();
    for (std::size_t i = 0; i < _sizePoints; i++)
    {
        point = readPoint();
        points.AddPoint(point);
    }

    return points;
}

std::shared_ptr<ConcreteFigureLP> BINLPReader::readFigureLP()
{
    auto figure = std::make_shared<FigureLP>();

    figure->setPoints(readPoints());
    figure->setLinks(readLinks());

    return std::make_shared<ConcreteFigureLP>(figure);
}

void BINLPReader::readSizePoints()
{
    _instream >> _sizePoints;
    if (_instream.fail() || _instream.bad())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void BINLPReader::readSizeLinks()
{
    _instream >> _sizeLinks;
    if (_instream.fail() || _instream.bad())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}
