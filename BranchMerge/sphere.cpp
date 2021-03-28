#include "sphere.h"

Sphere::Sphere(Point &p, double r) : Shape3d(p, "Sphere"), radius(r) {}

bool Sphere::contains(const Point &p) const
{
   if (fabs(location.distance(p)) <= radius) return true;
   return false;
}

double Sphere::volume() const
{
   return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
}
