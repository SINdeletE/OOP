//
// Created by nuelex on 18/05/25.
//

#ifndef TRANSFORMMANAGEREXCEPTION_HPP
#define TRANSFORMMANAGEREXCEPTION_HPP
#include <exception>

#include "../../BaseException.hpp"


class ErrorTransformManager_invalid_object : public BaseException
{
public:
    ErrorTransformManager_invalid_object(const char *filename,
            const char *classname,
            const long line,
            const char *time,
            const char *error_info = "Transform Manager: Invalid object") noexcept : BaseException(filename, classname, line, time, error_info) {}
};

class ErrorTransformManager_invalid_params : public BaseException
{
public:
    ErrorTransformManager_invalid_params(const char *filename,
            const char *classname,
            const long line,
            const char *time,
            const char *error_info = "Transform Manager: Invalid params") noexcept : BaseException(filename, classname, line, time, error_info) {}
};

class ErrorTransformManager_bad_alloc : public BaseException
{
public:
    ErrorTransformManager_bad_alloc(const char *filename,
            const char *classname,
            const long line,
            const char *time,
            const char *error_info = "Transform Manager: bad alloc") noexcept : BaseException(filename, classname, line, time, error_info) {}
};



#endif //TRANSFORMMANAGEREXCEPTION_HPP
