#ifndef POINT_H
#define POINT_H

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

struct Point
{
   double xLoc, yLoc, zLoc;
   Point(double, double, double);
   double distance(const Point &) const;
    
   Point operator-(const Point&) const;
};

std::ostream& operator<<(std::ostream& os, const Point &);
#endif
