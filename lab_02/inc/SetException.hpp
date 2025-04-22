#pragma once

#include "BaseException.hpp"

class ErrorSet_BadSize : public BaseError
{
    public:
    ErrorSet_BadSize(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid size value") : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorSet_BadAlloc : public BaseError
{
    public:
    ErrorSet_BadAlloc(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Bad alloc") : BaseError(filename, classname, line, Currenttime, error_info) {}
};
