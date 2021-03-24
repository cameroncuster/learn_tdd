#ifndef PRISMTEST_H
#define PRISMTEST_H

#include "shape3dTest.h"

class PrismTest : public Shape3dTest
{
   double xdim, ydim, zdim;
public:
   PrismTest(PointTest &p, double xdim=1.0, double ydim=1.0, double zdim=1.0);

   bool contains(const PointTest &p) const;
   double volume() const;
};

#endif
