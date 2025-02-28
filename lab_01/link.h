#ifndef LINK_H
#define LINK_H

#include <cstdio>
#include <cstddef>

#include "error.h"

struct link_t
{
    size_t beg;
    size_t end;
};

link_t link_init();
int is_link_is_valid(const link_t &link, const size_t points_size);

err_t link_read(link_t &link, FILE *file);

#endif // LINK_H
