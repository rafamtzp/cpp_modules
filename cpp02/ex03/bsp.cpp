#include "Point.hpp"

static bool onSameSide( Point const l1, Point l2, 
                       Point opp, Point point)
{
    Point line(l2 - l1);
    Point lp(point - l1);
    Point lo(opp - l1);

    Fixed crossp = line.getx() * lp.gety() - line.gety() * lp.getx();
    Fixed crosso = line.getx() * lo.gety() - line.gety() * lo.getx();

    if ((crossp < 0 && crosso < 0) || (crossp >= 0 && crosso >= 0))
        return (true);
    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (onSameSide(a, b, c, point) && onSameSide(b, c, a, point) &&
        onSameSide(a, c, b, point))
        return (true);
    return (false);
}
