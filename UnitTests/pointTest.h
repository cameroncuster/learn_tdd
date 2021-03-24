#ifndef POINTTEST_H
#define POINTTEST_H

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

struct PointTest
{
   double xLoc, yLoc, zLoc;
   PointTest(double, double, double);
   double distance(const PointTest &) const;
    
   PointTest operator-(const PointTest&) const;
};

std::ostream& operator<<(std::ostream& os, const PointTest &);
#endif
