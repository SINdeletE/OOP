#include <cstdlib>
#include <cmath>

#include "points.h"
#include "consts.h"

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

int points_are_equal(const point_t &point_1, const point_t &point_2)
{
    int res = 1;

    if (fabs(point_1.x - point_2.x) >= EPS)
        res = 0;
    else if (fabs(point_1.y - point_2.y) >= EPS)
        res = 0;
    else if (fabs(point_1.z - point_2.z) >= EPS)
        res = 0;

    return res;
}

// Функция проверяет, является ли точка в файле повторяющейся
int is_point_in_points(const points_t &points, const size_t size, const point_t &point)
{
    int res = 0;

    for (size_t i = 0; res == 0 && i < size; i++)
        if (points_are_equal(points.array[i], point))
        {
            res = 1;
        }

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

err_t points_read_from_file(points_t &points, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    points_t tmp_points = points_init();
    err_t res = ERR_NONE;

    res = points_count_read(tmp_points.n, file);
    if (res == ERR_NONE)
    {
        res = points_array_alloc(tmp_points.array, tmp_points.n);

        if (res == ERR_NONE)
        {
            res = points_array_read_file(tmp_points.array, tmp_points.n, file);

            if (res == ERR_NONE)
                points = tmp_points;
            else
                points_free(tmp_points);
        }
    }

    return res;
}

err_t points_read(points_t &points, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    points_t tmp_points = points_init();
    err_t res = ERR_NONE;

    res = points_read_from_file(tmp_points, file);

    if (res == ERR_NONE)
        points = tmp_points;

    return res;
}
