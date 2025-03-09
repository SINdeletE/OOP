#include <cstdlib>
#include <cmath>

#include "points.h"

#define EPS std::numeric_limits<double>::epsilon()

points_t points_init()
{
    return (points_t){0, NULL};
}

size_t points_get_size(const points_t &points)
{
    return points.n;
}

err_t points_array_alloc(point_t* &arr, const size_t n)
{
    if (n == 0) return ERR_POINTS_INVALID_ALLOC;

    err_t res = ERR_NONE;

    arr = (point_t *)calloc(n, sizeof(point_t));
    if (! arr)
        res = ERR_POINTS_INVALID_ALLOC;

    return res;
}

void points_free(points_t &points)
{
    free(points.array);

    points.n = 0;
    points.array = NULL;
}

void points_array_free(point_t* &points_array)
{
    free(points_array);

    points_array = NULL;
}

bool points_are_equal(const point_t &point_1, const point_t &point_2)
{
    bool res = true;

    if (fabs(point_1.x - point_2.x) >= EPS)
        res = false;
    else
    {
        if (fabs(point_1.y - point_2.y) >= EPS)
            res = false;
        else
        {
            if (fabs(point_1.z - point_2.z) >= EPS)
                res = false;
        }
    }

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
bool is_point_in_points(const points_t &points, const size_t size, const point_t &point)
{
    bool res = false;

    for (size_t i = 0; res == false && i < size; i++)
        if (points_are_equal(points.array[i], point))
        {
            res = true;
        }

    return res;
}

// Функция проверяет, является ли массив точек пустым
bool is_points_empty(const points_t &points)
{
    return ! points.array;
}

err_t points_count_read(size_t &n, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    long long sign_detector;

    err_t res = ERR_NONE;

    if (fscanf(file, "%lld", &sign_detector) != 1 || sign_detector <= 0)
        res = ERR_FILE_INVALID_DATA;
    else
        n = (size_t)sign_detector;

    return res;
}

err_t points_are_valid(const points_t &points)
{
    err_t res = ERR_NONE;

    for (size_t i = 0; res == ERR_NONE && i < points.n; i++)
    {
        if (is_point_in_points(points, i, points.array[i]))
            res = ERR_POINTS_SAME_POINTS;
    }

    return res;
}

err_t points_array_read_file(point_t* &array, const size_t n, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    err_t res = ERR_NONE;

    for (size_t i = 0; res == ERR_NONE && i < n; i++)
        res = point_read(array[i], file);

    return res;
}

err_t points_read(points_t &points, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    err_t res = ERR_NONE;

    res = points_count_read(points.n, file);
    if (res == ERR_NONE)
    {
        res = points_array_alloc(points.array, points.n);

        if (res == ERR_NONE)
        {
            res = points_array_read_file(points.array, points.n, file);

            if (res != ERR_NONE)
                points_array_free(points.array);
        }
    }

    return res;
}
