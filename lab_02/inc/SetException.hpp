#pragma once

#include "BaseException.hpp"

class ErrorSet_BadSize : public BaseError
{
    public:
    ErrorSet_BadSize(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid size value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorSet_IsEmpty : public BaseError
{
    public:
    ErrorSet_IsEmpty(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Set is empty") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorSet_BadAlloc : public BaseError
{
    public:
    ErrorSet_BadAlloc(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Bad alloc") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};






class ErrorSetIterator_IsInvalid : public BaseError
{
    public:
    ErrorSetIterator_IsInvalid(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Iterator is invalid") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorConstSetIterator_IsInvalid : public BaseError
{
    public:
    ErrorConstSetIterator_IsInvalid(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Const Iterator is invalid") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};



class ErrorSetIterator_BadOffset : public BaseError
{
    public:
    ErrorSetIterator_BadOffset(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid offset value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorConstSetIterator_BadOffset : public BaseError
{
    public:
    ErrorConstSetIterator_BadOffset(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid offset value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};
