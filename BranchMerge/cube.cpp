#include "cube.h"

Cube::Cube(Point &p, double l) : Shape3d(p, "Cube"), length(l) {}

bool Cube::contains(const Point &p) const
{
   return (fabs(location.xLoc-p.xLoc) <= length / 2.0 &&
        fabs(location.yLoc-p.yLoc) <= length / 2.0 &&
        fabs(location.zLoc-p.zLoc) <= length / 2.0);
}

double Cube::volume() const
{
   return length * length * length;
}
