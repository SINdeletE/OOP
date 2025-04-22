#pragma once

#include "BaseException.hpp"

class ErrorList_BadSize : public BaseError
{
    public:
    ErrorList_BadSize(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid size value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorList_IsEmpty : public BaseError
{
    public:
    ErrorList_IsEmpty(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "List is empty") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorList_BadAlloc : public BaseError
{
    public:
    ErrorList_BadAlloc(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Bad alloc") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};






class ErrorListIterator_IsInvalid : public BaseError
{
    public:
    ErrorListIterator_IsInvalid(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Iterator is invalid") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorConstListIterator_IsInvalid : public BaseError
{
    public:
    ErrorConstListIterator_IsInvalid(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Const Iterator is invalid") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};



class ErrorListIterator_BadOffset : public BaseError
{
    public:
    ErrorListIterator_BadOffset(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid offset value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};

class ErrorConstListIterator_BadOffset : public BaseError
{
    public:
    ErrorConstListIterator_BadOffset(const char * filename,
        const char * classname,
        long line,
        const char* Currenttime,
        const char * error_info = "Invalid offset value") noexcept : BaseError(filename, classname, line, Currenttime, error_info) {}
};
