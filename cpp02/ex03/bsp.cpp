#include "Point.hpp"

float    area(const Point& a, const Point& b, const Point& c)
{
    float    areaSize;

    areaSize = (a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat()) +
             b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat()) +
             c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat()));
    areaSize = areaSize / 2.0f;
    if (areaSize >= 0)
        return (areaSize);
    else
        return (-areaSize);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float    ABC;
    float    PAB;
    float    PAC;
    float    PBC;
    float    areaSum;
    float    size_diff;

    ABC = area(a, b, c);
    PAB = area(point, a, b);
    PAC = area(point, a , c);
    PBC = area(point, b, c);

    if (PAB == 0 || PAC == 0 || PBC == 0)
        return (false);
    areaSum = PAB + PAC + PBC;
    size_diff = ABC - areaSum;
    if (size_diff < 0)
        size_diff = -size_diff;
    if (size_diff < 1e-6f)
        return (true);
    return (false);
}
