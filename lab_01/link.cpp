#include "link.h"

link_t link_init()
{
    return (link_t){0, 0};
}

int link_read(link_t &link, FILE *file)
{
    link_t tmp_link = link_init();

    if (fscanf(file, "%zu%zu", &tmp_link.beg, &tmp_link.end) != 2)
        return 1;

    link = tmp_link;

    return 0;
}

