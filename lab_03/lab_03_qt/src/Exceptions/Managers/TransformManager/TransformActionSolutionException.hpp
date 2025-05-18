//
// Created by nuelex on 18/05/25.
//

#ifndef TRANSFORMACTIONSOLUTIONEXCEPTION_HPP
#define TRANSFORMACTIONSOLUTIONEXCEPTION_HPP
#include "../../BaseException.hpp"

class ErrorTransformActionSolution_invalid_object : public BaseException
{
public:
    ErrorTransformActionSolution_invalid_object(const char *filename,
            const char *classname,
            const long line,
            const char *time,
            const char *error_info = "Transform action solution: Invalid object") noexcept : BaseException(filename, classname, line, time, error_info) {}
};

#endif //TRANSFORMACTIONSOLUTIONEXCEPTION_HPP
