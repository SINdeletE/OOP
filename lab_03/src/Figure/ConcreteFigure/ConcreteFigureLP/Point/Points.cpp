//
// Created by nuelex on 08/05/25.
//

#include "Points.hpp"
#include "../../../../Exceptions/Figure/PointsException.hpp"

void Points::AddPoint(const double& x, const double& y, const double& z)
{
    try
    {
        points.emplace_back(x, y, z);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorPoints_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

Points& Points::operator=(const Points& points_arg)
{
    points = points_arg.points;
    return *this;
}

