//
// Created by nuelex on 26/05/25.
//

#include "CSVLPReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"

CSVLPReader::CSVLPReader(const std::string& filename) : _qfile(filename.c_str()), _sizePoints(0), _sizeLinks(0)
{
    _qfile.open(QFile::ReadOnly | QFile::Text);

    if (! _qfile.isOpen())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _in.setDevice(&_qfile);
}

Link CSVLPReader::readLink()
{
    std::size_t BeginID = 0, EndID = 0;

    QVector<unsigned long long> row{};

    if (this->is_open() && ! _in.atEnd())
    {
        const QString line = _in.readLine();
        QStringList fields = line.split(';', Qt::SkipEmptyParts);

        for (QString field : fields)
        {
            field = field.trimmed().remove('"');

            bool flag;
            const unsigned long long value = field.toULongLong(&flag);
            if (flag)
            {
                row.append(value);
            }
        }

        if (row.size() != 2)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        BeginID = row[0];
        EndID = row[1];
    }

    if (BeginID == EndID || BeginID >= _sizePoints || EndID >= _sizePoints)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return {BeginID, EndID};
}

Point CSVLPReader::readPoint()
{
    QVector<double> row{};

    if (this->is_open() && ! _in.atEnd())
    {
        const QString line = _in.readLine();
        QStringList fields = line.split(';', Qt::SkipEmptyParts);

        for (QString field : fields)
        {
            field = field.trimmed().remove('"');

            bool flag;
            const double value = field.toDouble(&flag);
            if (flag)
            {
                row.append(value);
            }
        }

        if (row.size() != 3)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    return {row[0], row[1], row[2]};
}

bool CSVLPReader::linkIsCorrect(Links &links, const Link &link)
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

Links CSVLPReader::readLinks()
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

Points CSVLPReader::readPoints()
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

std::shared_ptr<ConcreteFigureLP> CSVLPReader::readFigureLP()
{
    auto figure = std::make_shared<FigureLP>();

    figure->setPoints(readPoints());
    figure->setLinks(readLinks());

    return std::make_shared<ConcreteFigureLP>(figure);
}

void CSVLPReader::readSizePoints()
{
    const QString line = _in.readLine();
    QStringList fields = line.split(';', Qt::SkipEmptyParts);
    QVector<int> row;

    for (QString field : fields)
    {
        field = field.trimmed().remove('"');

        bool flag;
        int value = field.toInt(&flag);
        if (flag)
        {
            row.append(value);
        }

        if (row.size() != 1)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    int tmp = row[0];
    if (tmp <= 0)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _sizePoints = static_cast<std::size_t>(tmp);
}

void CSVLPReader::readSizeLinks()
{
    const QString line = _in.readLine();
    QStringList fields = line.split(';', Qt::SkipEmptyParts);
    QVector<int> row;

    for (QString field : fields)
    {
        field = field.trimmed().remove('"');

        bool flag;
        int value = field.toInt(&flag);
        if (flag)
        {
            row.append(value);
        }

        if (row.size() != 1)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

    int tmp = row[0];
    if (tmp <= 0)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _sizeLinks = static_cast<std::size_t>(tmp);
}

CSVLPReader::~CSVLPReader()
{
    if (this->CSVLPReader::is_open())
        _qfile.close();
}



