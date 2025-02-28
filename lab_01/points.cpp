#include <cstdlib>
#include <cmath>

#include "points.h"
#include "consts.h"

points_t points_init()
{
    return (points_t){0, NULL};
}

size_t points_get_size(points_t &points)
{
    return points.n;
}

err_t points_alloc(points_t &points, const size_t n)
{
    point_t *array = NULL;

    array = (point_t *)calloc(n, sizeof(point_t));
    if (! array)
        return ERR_POINTS_INVALID_ALLOC;

    points.array = array;
    points.n = n;

    return ERR_NONE;
}

void points_free(points_t &points)
{
    free(points.array);

    points.n = 0;
    points.array = NULL;
}

int points_are_equal(const point_t &point_1, const point_t &point_2)
{
    int res = 1;

    if (fabs(point_1.x - point_2.x) >= EPS)
        res = 0;
    else if (fabs(point_1.y - point_2.y) >= EPS)
        res = 0;
    else if (fabs(point_1.x - point_2.x) >= EPS)
        res = 0;

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
int is_point_in_points(const points_t &points, const size_t size, const point_t &point)
{
    int res = 0;

    for (size_t i = 0; ! res && i < size; i++)
        if (points_are_equal(points.array[i], point))
            res = 1;

    return res;
}

// Функция проверяет, является ли массив точек пустым
int is_points_empty(const points_t &points)
{
    return ! points.array;
}

err_t points_count_read(size_t &n, FILE *file)
{
    size_t tmp_n;
    long long sign_detector;

    if (fscanf(file, "%lld", &sign_detector) != 1)
        return ERR_FILE_INVALID_DATA;

    n = (size_t)sign_detector;

    return ERR_NONE;
}

err_t points_read(points_t &points, FILE *file)
{
    points_t tmp_points = points_init();
    err_t res = ERR_NONE;

    res = points_count_read(tmp_points.n, file);
    if (! res)
        res = points_alloc(tmp_points, tmp_points.n);

    for (size_t i = 0; ! res && i < tmp_points.n; i++)
    {
        res = point_read(tmp_points.array[i], file);

        if (! res && is_point_in_points(tmp_points, i, tmp_points.array[i]))
            res = ERR_POINTS_SAME_POINTS;
    }

    if (res)
        points_free(tmp_points);
    else
        points = tmp_points;

    return res;
}
