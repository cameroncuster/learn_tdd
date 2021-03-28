#ifndef PRISM_H
#define PRISM_H

#include "shape3d.h"

class Prism : public Shape3d
{
   double xdim, ydim, zdim;
public:
   Prism(Point &p, double xdim=1.0, double ydim=1.0, double zdim=1.0);

   bool contains(const Point &p) const;
   double volume() const;
};

#endif
