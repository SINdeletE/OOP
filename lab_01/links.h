#ifndef LINKS_H
#define LINKS_H

#include "link.h"
#include "error.h"

struct links_t
{
    size_t n;
    link_t *array;
};

err_t links_alloc(links_t &links, const size_t n);
void links_free(links_t &links);

#endif // LINKS_H
