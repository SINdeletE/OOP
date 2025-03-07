#include "link.h"

link_t link_init()
{
    return (link_t){0, 0};
}

bool is_link_field_is_valid(const size_t link_field, const size_t points_size)
{
    return link_field < points_size;
}

// Функция проверяет, указывает ли link на одинаковые точки/не существующие точки
bool is_link_is_valid(const link_t &link, const size_t points_size)
{
    bool res = true;

    if (link.beg == link.end)
        res = false;
    else
    {
        if (! is_link_field_is_valid(link.beg, points_size))
            res = false;
        else
        {
            if (! is_link_field_is_valid(link.end, points_size))
                res = false;
        }
    }

    return res;
}

err_t link_read(link_t &link, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    link_t tmp_link;
    err_t res = ERR_NONE;

    if (fscanf(file, "%zu%zu", &tmp_link.beg, &tmp_link.end) != 2)
        res = ERR_FILE_INVALID_DATA;
    else
        link = tmp_link;

    return res;
}

