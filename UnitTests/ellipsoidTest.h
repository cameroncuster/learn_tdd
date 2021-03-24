#ifndef ELLIPSOIDTEST_H
#define ELLIPSOIDTEST_H

#include "shape3dTest.h"

/********************************************************************//**
 * @class Ellipsoid
 **********************************************************************/
class EllipsoidTest : public Shape3dTest
{
   double xrad, yrad, zrad;
public:
   EllipsoidTest();
   EllipsoidTest(PointTest &p, double xrad, double yrad, double zrad);

   bool contains(const PointTest &p) const;
   double volume() const;
};
#endif
