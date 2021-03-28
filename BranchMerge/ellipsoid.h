#ifndef ELLIPSOID_H
#define ELLIPSOID_H

#include "shape3d.h"

/********************************************************************//**
 * @class Ellipsoid
 **********************************************************************/
class Ellipsoid : public Shape3d
{
   double xrad, yrad, zrad;
public:
   Ellipsoid();
   Ellipsoid(Point &p, double xrad, double yrad, double zrad);

   bool contains(const Point &p) const;
   double volume() const;
};
#endif
