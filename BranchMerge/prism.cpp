#include "prism.h"

Prism::Prism(Point &p, double x, double y, double z) : Shape3d(p, "Prism"), xdim(x), ydim(y), zdim(z) {}

bool Prism::contains(const Point &p) const
{
   return (fabs(location.xLoc-p.xLoc) <= xdim / 2.0 &&
        fabs(location.yLoc-p.yLoc) <= ydim / 2.0 &&
        fabs(location.zLoc-p.zLoc) <= zdim / 2.0);
}

double Prism::volume() const
{
   return xdim * ydim * zdim;
}
