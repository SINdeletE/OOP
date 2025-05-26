//
// Created by nuelex on 26/05/25.
//

#ifndef CSVLPREADER_HPP
#define CSVLPREADER_HPP
#include <QFile>
#include <qtextstream.h>

#include "../BaseLPReader.hpp"


class CSVLPReader : public BaseLPReader
{
public:
    CSVLPReader() = delete;
    explicit CSVLPReader(const std::string &filename);
    ~CSVLPReader() override;

    [[nodiscard]] Links readLinks() override;
    [[nodiscard]] Points readPoints() override;
    [[nodiscard]] std::shared_ptr<ConcreteFigureLP> readFigureLP() override;

    [[nodiscard]] bool is_open() const override { return _qfile.isOpen(); }

private:
    QFile _qfile;
    QTextStream _in{};

    std::size_t _sizePoints;
    std::size_t _sizeLinks;

    [[nodiscard]] Point readPoint();
    [[nodiscard]] Link readLink();
    [[nodiscard]] static bool linkIsCorrect(Links &links, const Link &link);

    void readSizePoints();
    void readSizeLinks();
};



#endif //CSVLPREADER_HPP
