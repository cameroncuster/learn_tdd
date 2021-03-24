#include "sphereTest.h"

SphereTest::SphereTest(PointTest &p, double r) : Shape3dTest(p, "Sphere"), radius(r) {}

bool SphereTest::contains(const PointTest &p) const
{
   if (fabs(location.distance(p)) <= radius) return true;
   return false;
}

double SphereTest::volume() const
{
   return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
}
