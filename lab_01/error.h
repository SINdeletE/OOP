#ifndef ERROR_H
#define ERROR_H

enum error_t
{
    ERR_NONE,

    ERR_FILE_NOT_FOUND,
    ERR_FILE_INVALID_STRUCTURE,
    ERR_FILE_INVALID_DATA,

    ERR_POINT_INVALID_READ,

    ERR_POINTS_INVALID_ALLOC
};

void error_msg(error_t error);

#endif // ERROR_H
