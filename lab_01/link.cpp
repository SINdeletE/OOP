#include "link.h"

link_t link_init()
{
    return (link_t){0, 0};
}

// Функция проверяет, указывает ли link на одинаковые точки/не существующие точки
int is_link_is_valid(const link_t &link, const size_t points_size)
{
    int res = 1;

    if (link.beg == link.end)
        res = 0;

    if (res && link.beg >= points_size)
        res = 0;

    if (res && link.end >= points_size)
        res = 0;

    return res;
}

err_t link_read(link_t &link, FILE *file)
{
    link_t tmp_link;

    err_t res = ERR_NONE;

    if (fscanf(file, "%zu%zu", &tmp_link.beg, &tmp_link.end) != 2)
        res = ERR_FILE_INVALID_DATA;

    if (! res)
        link = tmp_link;

    return res;
}

