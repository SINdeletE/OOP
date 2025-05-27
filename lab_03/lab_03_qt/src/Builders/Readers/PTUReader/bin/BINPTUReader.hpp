//
// Created by nuelex on 27/05/25.
//

#ifndef BINPTUREADER_HPP
#define BINPTUREADER_HPP
#include <fstream>

#include "../BasePTUReader.hpp"


class BINPTUReader : public BasePTUReader
{
public:
    BINPTUReader() = delete;
    explicit BINPTUReader(const std::string &filename);
    ~BINPTUReader() override = default;

    [[nodiscard]] Point readPosition() override;
    [[nodiscard]] Point readTarget() override;
    [[nodiscard]] Point readUp() override;

    [[nodiscard]] bool is_open() const override { return _instream.is_open(); }

private:
    std::ifstream _instream;

    [[nodiscard]] Point readPoint();
};



#endif //BINPTUREADER_HPP
