#include "links.h"

#include <cstdlib>

links_t links_init()
{
    return (links_t){0, NULL};
}

err_t links_array_alloc(link_t* &array, const size_t n)
{
    err_t res = ERR_NONE;

    array = (link_t *)calloc(n, sizeof(link_t));
    if (! array)
        res = ERR_LINKS_INVALID_ALLOC;

    return res;
}

void links_free(links_t &links)
{
    free(links.array);

    links.n = 0;
    links.array = NULL;
}

bool links_are_equal(const link_t &link_1, const link_t &link_2)
{
    int res = true;

    if (link_1.beg == link_2.end && link_1.end == link_2.beg)
        res = true;
    else
    {
        if (link_1.beg != link_2.beg)
            res = false;
        else
        {
            if (link_1.end != link_2.end)
                res = false;
        }
    }

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
int is_link_in_links(const links_t &links, const size_t size, const link_t &link)
{
    int res = 0;

    for (size_t i = 0; res == ERR_NONE && i < size; i++)
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

err_t links_array_read_file(link_t* &array, const size_t n, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    err_t res = ERR_NONE;

    for (size_t i = 0; res == ERR_NONE && i < n; i++)
        res = link_read(array[i], file);

    return res;
}

err_t links_are_valid(const links_t &links, const size_t points_size)
{
    err_t res = ERR_NONE;

    for (size_t i = 0; res == ERR_NONE && i < links.n; i++)
    {
        if (! is_link_is_valid(links.array[i], points_size))
            res = ERR_LINKS_INVALID_LINK;
        else if (is_link_in_links(links, i, links.array[i]))
            res = ERR_LINKS_SAME_LINKS;
    }

    return res;
}

err_t links_read_from_file(links_t &links, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    links_t tmp_links = links_init();
    err_t res = ERR_NONE;

    res = links_count_read(tmp_links.n, file);

    if (res == ERR_NONE)
    {
        res = links_array_alloc(tmp_links.array, tmp_links.n);

        if (res == ERR_NONE)
        {
            res = links_array_read_file(tmp_links.array, tmp_links.n, file);

            if (res == ERR_NONE)
                links = tmp_links;
            else
                links_free(tmp_links);
        }
    }

    return res;
}

err_t links_read(links_t &links, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    links_t tmp_links = links_init();
    err_t res = ERR_NONE;

    res = links_read_from_file(tmp_links, file);

    if (res == ERR_NONE)
        links = tmp_links;

    return res;
}
