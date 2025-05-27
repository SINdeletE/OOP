//
// Created by nuelex on 27/05/25.
//

#ifndef TARGZREADER_HPP
#define TARGZREADER_HPP
#include <filesystem>

#include "../BaseArchiveReader.hpp"


class TARGZReader : public BaseArchiveReader
{
public:
    TARGZReader() = delete;
    TARGZReader(const std::string &path);

    ~TARGZReader() override;

    void next()
    {
        ++_iter;
    }
    std::string current() const override
    {
        const auto value = *_iter;
        const auto full_path = value.path();
        const auto cur_path = std::filesystem::current_path();
        const auto relative_path = full_path.lexically_relative(cur_path);

        return relative_path.string();
    }
    bool isEnd() const override
    {
        return _iter == end(_iter);
    }

private:
    std::string _dir{"test"};
    std::filesystem::directory_iterator _iter;

    bool targzExtract(const std::string &path) const;
};



#endif //TARGZREADER_HPP
