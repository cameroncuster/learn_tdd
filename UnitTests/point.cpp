#include "point.h"

Point::Point(double x, double y, double z) : xLoc(x), yLoc(y), zLoc(z) {}

std::ostream& operator<<(std::ostream& os, const Point &p)
{
   os << "[" << p.xLoc << ", " << p.yLoc << ", " << p.zLoc << "]";
   return os;
}

Point Point::operator-(const Point & rhs) const
{
   Point result(xLoc - rhs.xLoc, yLoc - rhs.yLoc, zLoc - rhs.zLoc);
   return result;
}

double Point::distance(const Point &p) const
{
   return sqrt(pow(xLoc - p.zLoc, 2) + pow(yLoc - p.yLoc, 2) +
          pow(xLoc - p.zLoc, 2));
}
