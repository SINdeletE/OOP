//
// Created by nuelex on 13/05/25.
//

#ifndef TXTLPREADER_HPP
#define TXTLPREADER_HPP
#include "../BaseLPReader.hpp"


class TXTLPReader : public BaseLPReader
{
public:
    TXTLPReader() = default;
    explicit TXTLPReader(const std::string &filename);
    ~TXTLPReader() override = default;

    [[nodiscard]] Links readLinks() override;
    [[nodiscard]] Points readPoints() override;
    [[nodiscard]] std::shared_ptr<ConcreteFigureLP> readFigureLP() override;

    [[nodiscard]] bool is_open() const override { return _instream.is_open(); }

private:
    std::ifstream _instream;
    std::size_t size;

    [[nodiscard]] Point readPoint();
    [[nodiscard]] Link readLink();
    [[nodiscard]] bool linkIsCorrect(Links &links, const Link &link);
};



#endif //TXTLPREADER_HPP
