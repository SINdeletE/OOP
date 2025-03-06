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
void links_free(links_t &links);

err_t links_are_valid(const links_t &links, const size_t points_size);

err_t links_read(links_t &links, FILE *file);
err_t links_are_valid(const links_t &links, const size_t points_size);

#endif // LINKS_H
