#ifndef SPHERETEST_H
#define SPHERETEST_H

#include "shape3dTest.h"

class SphereTest : public Shape3dTest
{
   double radius;
public:
   SphereTest(PointTest &p, double r = 1.0);

   bool contains(const PointTest &p) const;
   double volume() const;
};

#endif
