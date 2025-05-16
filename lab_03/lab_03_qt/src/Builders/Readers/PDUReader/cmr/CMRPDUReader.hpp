//
// Created by nuelex on 16/05/25.
//

#ifndef CMRPDUREADER_HPP
#define CMRPDUREADER_HPP
#include <fstream>

#include "../BasePDUReader.hpp"


class CMRPDUReader : public BasePDUReader
{
public:
    CMRPDUReader() = delete;
    explicit CMRPDUReader(const std::string &filename);
    ~CMRPDUReader() override = default;

    [[nodiscard]] Point readPosition() override;
    [[nodiscard]] Point readTarget() override;
    [[nodiscard]] Point readUp() override;

    [[nodiscard]] bool is_open() const override { return _instream.is_open(); }

private:
    std::ifstream _instream;

    [[nodiscard]] Point readPoint();
};



#endif //CMRPDUREADER_HPP
