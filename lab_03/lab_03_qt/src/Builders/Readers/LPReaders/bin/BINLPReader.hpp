//
// Created by nuelex on 27/05/25.
//

#ifndef BINLPREADER_HPP
#define BINLPREADER_HPP
#include "../BaseLPReader.hpp"


class BINLPReader : public BaseLPReader
{
public:
    BINLPReader() = delete;
    explicit BINLPReader(const std::string &filename);
    ~BINLPReader() override = default;

    [[nodiscard]] Links readLinks() override;
    [[nodiscard]] Points readPoints() override;
    [[nodiscard]] std::shared_ptr<ConcreteFigureLP> readFigureLP() override;

    [[nodiscard]] bool is_open() const override { return _instream.is_open(); }

private:
    std::ifstream _instream;
    std::size_t _sizePoints;
    std::size_t _sizeLinks;

    [[nodiscard]] Point readPoint();
    [[nodiscard]] Link readLink();
    [[nodiscard]] static bool linkIsCorrect(Links &links, const Link &link);

    void readSizePoints();
    void readSizeLinks();
};



#endif //BINLPREADER_HPP
