//
// Created by nuelex on 27/05/25.
//

#include "CSVPTUReader.hpp"

#include "../../../../Exceptions/Reader/ReaderException.hpp"

CSVPTUReader::CSVPTUReader(const std::string& filename) : _qfile(filename.c_str())
{
    _qfile.open(QFile::ReadOnly | QFile::Text);

    if (! _qfile.isOpen())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorReader_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _in.setDevice(&_qfile);
}

Point CSVPTUReader::readPoint()
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

Point CSVPTUReader::readPosition()
{
    return readPoint();
}

Point CSVPTUReader::readTarget()
{
    return readPoint();
}

Point CSVPTUReader::readUp()
{
    return readPoint();
}
