#include "Point.hpp"
#include <cmath>

static Fixed   line(Point const a, Point const b, const Fixed x)
{
    return (((a.gety() - b.gety()) * (x)) / (a.getx() - b.getx()));
}

static bool onSameSide( Point const l1, Point const l2, 
                       Point const opp, Point const point)
{
    if (point.gety() < line(l1, l2, point.getx()) && 
        opp.gety() < line(l1, l2, opp.gety()))
        return (true);
    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (onSameSide(a, b, c, point) || onSameSide(b, c, a, point) ||
        onSameSide(a, c, b, point))
        return (true);
    return (false);
}
