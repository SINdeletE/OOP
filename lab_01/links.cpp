#include "links.h"

#include <cstdlib>

links_t links_init()
{
    return (links_t){0, NULL};
}

err_t links_alloc(links_t &links, const size_t n)
{
    link_t *array = NULL;

    err_t res = ERR_NONE;

    array = (link_t *)calloc(n, sizeof(link_t));
    if (! array)
        res = ERR_LINKS_INVALID_ALLOC;

    if (! res)
    {
        links.array = array;
        links.n = n;
    }

    return res;
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

    if (link_1.beg == link_2.end && link_1.end == link_2.beg)
        res = 1;

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
int is_link_in_links(const links_t &links, const size_t size, const link_t &link)
{
    int res = 0;

    for (size_t i = 0; ! res && i < size; i++)
        if (links_are_equal(links.array[i], link))
            res = 1;

    return res;
}

err_t links_count_read(size_t &n, FILE *file)
{
    size_t tmp_n;
    long long sign_detector;

    err_t res = ERR_NONE;

    if (fscanf(file, "%lld", &sign_detector) != 1 || sign_detector <= 0)
        res = ERR_FILE_INVALID_DATA;
    else
        n = (size_t)sign_detector;

    return res;
}

err_t links_read(links_t &links, FILE *file, const size_t points_size)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    links_t tmp_links = links_init();
    err_t res = ERR_NONE;

    res = links_count_read(tmp_links.n, file);
    if (! res)
        res = links_alloc(tmp_links, tmp_links.n);

    for (size_t i = 0; ! res && i < tmp_links.n; i++)
        res = link_read(tmp_links.array[i], file);

    for (size_t i = 0; ! res && i < tmp_links.n; i++)
    {
        if (! is_link_is_valid(tmp_links.array[i], points_size))
            res = ERR_LINKS_INVALID_LINK;
        else if (is_link_in_links(tmp_links, i, tmp_links.array[i]))
            res = ERR_LINKS_SAME_LINKS;
    }

    if (res)
        links_free(tmp_links);
    else
        links = tmp_links;

    return res;
}
