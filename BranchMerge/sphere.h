#ifndef SPHERE_H
#define SPHERE_H

#include "shape3d.h"

class Sphere : public Shape3d
{
   double radius;
public:
   Sphere(Point &p, double r = 1.0);

   bool contains(const Point &p) const;
   double volume() const;
};

#endif
