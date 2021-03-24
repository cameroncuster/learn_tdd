/********************************************************************//**
 * @file
 ***********************************************************************/
#include "ellipsoidTest.h"

EllipsoidTest::EllipsoidTest(PointTest &p, double x, double y, double z) : Shape3dTest(p, "Ellipsoid"), xrad(x), yrad(y), zrad(z) {}

bool EllipsoidTest::contains(const PointTest &p) const
{
   if (location.xLoc == p.xLoc && location.yLoc == p.yLoc &&
       location.zLoc == p.zLoc) return true;

   double x_dist = pow(location.xLoc-p.xLoc,2) / pow(xrad, 2);
   double y_dist = pow(location.yLoc-p.yLoc,2) / pow(yrad, 2);
   double z_dist = pow(location.zLoc-p.zLoc,2) / pow(zrad, 2);

   return ((x_dist + y_dist + z_dist) <= 1.0);
}

double EllipsoidTest::volume() const
{
   return 4.0 / 3.0 * M_PI * xrad * yrad * zrad;
}
