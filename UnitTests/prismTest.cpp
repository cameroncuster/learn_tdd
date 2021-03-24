#include "prismTest.h"

PrismTest::PrismTest(PointTest &p, double x, double y, double z) : Shape3dTest(p, "Prism"), xdim(x), ydim(y), zdim(z) {}

bool PrismTest::contains(const PointTest &p) const
{
   return (fabs(location.xLoc-p.xLoc) <= xdim / 2.0 &&
        fabs(location.yLoc-p.yLoc) <= ydim / 2.0 &&
        fabs(location.zLoc-p.zLoc) <= zdim / 2.0);
}

double PrismTest::volume() const
{
   return xdim * ydim * zdim;
}
