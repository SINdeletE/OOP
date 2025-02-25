#ifndef ERROR_H
#define ERROR_H

enum err_t
{
    ERR_NONE,

    ERR_FILE_NOT_FOUND,
    ERR_FILE_INVALID_STRUCTURE,
    ERR_FILE_INVALID_DATA,

    ERR_LINKS_INVALID_ALLOC,

    ERR_POINTS_INVALID_ALLOC,

    ERR_MODEL_IS_EMPTY
};

void error_msg(err_t error);

#endif // ERROR_H
