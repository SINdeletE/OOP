//
// Created by nuelex on 13/05/25.
//

#ifndef ERRORREADERINVALIDFILE_HPP
#define ERRORREADERINVALIDFILE_HPP
#include "../BaseException.hpp"


class ReaderException : public BaseException
{
public:
    ReaderException(const char *filename,
            const char *classname,
            const long line,
            const char *time,
            const char *error_info = "Reader: Invalid File") noexcept : BaseException(filename, classname, line, time, error_info) {}
};



#endif //ERRORREADERINVALIDFILE_HPP
