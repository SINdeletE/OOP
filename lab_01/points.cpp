#include <cstdlib>
#include <cmath>

#include "points.h"
#include "consts.h"

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
int is_point_in_points(const points_t &points, const point_t &point)
{
    int res = 0;

    for (size_t i = 0; ! res && i < points.n; i++)
        if (points_are_equal(points.array[i], point))
            res = 1;

    return res;
}
