//
// Created by nuelex on 13/05/25.
//

#include "TXTLPReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"


TXTLPReader::TXTLPReader(const std::string& filename) : size(0)
{
    _instream.open(filename, std::ios::in);

    if (! _instream.is_open())
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _instream >> size;
    if (_instream.fail() || _instream.bad())
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _instream.seekg(0, std::ios::beg);
}

Link TXTLPReader::readLink()
{
    std::size_t BeginID = 0, EndID = 0;

    if (this->is_open() && ! _instream.eof())
    {
        _instream.clear();
        _instream >> BeginID >> EndID;

        if (_instream.fail() || _instream.bad())
        {
            const time_t cur_time = time(nullptr);
            throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    if (BeginID == EndID || BeginID >= size || EndID >= size)
    {
        const time_t cur_time = time(nullptr);
        throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return {BeginID, EndID};
}

Point TXTLPReader::readPoint()
{
    double x = 0, y = 0, z = 0;

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

bool TXTLPReader::linkIsCorrect(Links &links, const Link &link)
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

Links TXTLPReader::readLinks()
{
    Links links{};
    Link link{};

    for (std::size_t i = 0; i < size; i++)
    {
        link = readLink();
        if (! linkIsCorrect(links, link))
        {
            const time_t cur_time = time(nullptr);
            throw ReaderException(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        links.AddLink(link);
    }

    return links;
}

Points TXTLPReader::readPoints()
{
    Points points{};
    Point point{};

    for (std::size_t i = 0; i < size; i++)
    {
        point = readPoint();
        points.AddPoint(point);
    }

    return points;
}

std::shared_ptr<ConcreteFigureLP> TXTLPReader::readFigureLP()
{
    ConcreteFigureLP figure{};

    figure.setPoints(readPoints());
    figure.setLinks(readLinks());

    return std::make_shared<ConcreteFigureLP>(figure);
}

