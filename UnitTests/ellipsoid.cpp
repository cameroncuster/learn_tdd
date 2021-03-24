/********************************************************************//**
 * @file
 ***********************************************************************/
#include "ellipsoid.h"

Ellipsoid::Ellipsoid(Point &p, double x, double y, double z) : Shape3d(p, "Ellipsoid"), xrad(x), yrad(x), zrad(z) {}

bool Ellipsoid::contains(const Point &p) const
{
   if (location.xLoc == p.xLoc && location.yLoc == p.yLoc &&
       location.zLoc == p.zLoc) return true;

   double x_dist = pow(location.xLoc-p.xLoc,2) / pow(xrad, 2);
   double y_dist = pow(location.yLoc-p.yLoc,2) / pow(yrad, 2);
   double z_dist = pow(location.zLoc-p.zLoc,2) / pow(zrad, 2);

   return ((x_dist + y_dist + z_dist) <= 1.0);
}

double Ellipsoid::volume() const
{
   return 4.0 / 3.0 * M_PI * xrad * yrad * zrad;
}
