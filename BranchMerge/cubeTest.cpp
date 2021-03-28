#include "cubeTest.h"

CubeTest::CubeTest(PointTest &p, double l) : Shape3dTest(p, "Cube"), length(l) {}

bool CubeTest::contains(const PointTest &p) const
{
   return (fabs(location.xLoc-p.xLoc) <= length / 2.0 &&
        fabs(location.yLoc-p.yLoc) <= length / 2.0 &&
        fabs(location.zLoc-p.zLoc) <= length / 2.0);
}

double CubeTest::volume() const
{
   return length * length * length;
}
