#include "links.h"

#include <cstdlib>

err_t links_alloc(links_t &links, const size_t n)
{
    link_t *array = NULL;

    array = (link_t *)calloc(n, sizeof(link_t));
    if (! array)
        return ERR_LINKS_INVALID_ALLOC;

    links.array = array;
    links.n = n;

    return ERR_NONE;
}

void links_free(links_t &links)
{
    free(links.array);

    links.n = 0;
    links.array = NULL;
}

int links_are_equal(const link_t &link_1, const link_t &link_2)
{
    int res = 1;

    if (link_1.beg != link_2.beg)
        res = 0;
    else if (link_1.end != link_2.end)
        res = 0;

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
int is_link_in_links(const links_t &links, const link_t &link)
{
    int res = 0;

    for (size_t i = 0; ! res && i < links.n; i++)
        if (links_are_equal(links.array[i], link))
            res = 1;

    return res;
}

