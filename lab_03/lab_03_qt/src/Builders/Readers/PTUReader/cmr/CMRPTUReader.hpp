//
// Created by nuelex on 16/05/25.
//

#ifndef CMRPDUREADER_HPP
#define CMRPDUREADER_HPP
#include <fstream>

#include "../BasePTUReader.hpp"


class CMRPTUReader : public BasePTUReader
{
public:
    CMRPTUReader() = delete;
    explicit CMRPTUReader(const std::string &filename);
    ~CMRPTUReader() override = default;

    [[nodiscard]] Point readPosition() override;
    [[nodiscard]] Point readTarget() override;
    [[nodiscard]] Point readUp() override;

    [[nodiscard]] bool is_open() const override { return _instream.is_open(); }

private:
    std::ifstream _instream;

    [[nodiscard]] Point readPoint();
};



#endif //CMRPDUREADER_HPP
