#ifndef CUBETEST_H
#define CUBETEST_H

#include "shape3dTest.h"

class CubeTest : public Shape3dTest
{
   double length;
public:
   CubeTest(PointTest &p, double l = 1.0);

   bool contains(const PointTest &p) const;
   double volume() const;
};

#endif
