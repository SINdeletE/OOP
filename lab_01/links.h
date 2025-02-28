#ifndef LINKS_H
#define LINKS_H

#include "link.h"
#include "error.h"

struct links_t
{
    size_t n;
    link_t *array;
};

links_t links_init();
err_t links_alloc(links_t &links, const size_t n);
void links_free(links_t &links);

err_t links_read(links_t &links, FILE *file, const size_t points_size);

#endif // LINKS_H
