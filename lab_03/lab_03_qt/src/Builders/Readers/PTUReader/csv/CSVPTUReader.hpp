//
// Created by nuelex on 27/05/25.
//

#ifndef CSVPTUREADER_HPP
#define CSVPTUREADER_HPP
#include <QFile>
#include <qtextstream.h>
#include <string>

#include "../BasePTUReader.hpp"
#include "../../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"


class CSVPTUReader : public BasePTUReader
{
public:
    CSVPTUReader() = delete;
    explicit CSVPTUReader(const std::string &filename);
    ~CSVPTUReader() override = default;

    [[nodiscard]] Point readPosition() override;
    [[nodiscard]] Point readTarget() override;
    [[nodiscard]] Point readUp() override;

    [[nodiscard]] bool is_open() const override { return _qfile.isOpen(); }

private:
    QFile _qfile;
    QTextStream _in{};

    [[nodiscard]] Point readPoint();
};



#endif //CSVPTUREADER_HPP
