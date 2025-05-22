//
// Created by nuelex on 13/05/25.
//

#ifndef TXTLPREADER_HPP
#define TXTLPREADER_HPP
#include "../BaseLPReader.hpp"


class TXTLPReader : public BaseLPReader
{
public:
    TXTLPReader() = delete;
    explicit TXTLPReader(const std::string &filename);
    ~TXTLPReader() override = default;

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



#endif //TXTLPREADER_HPP
