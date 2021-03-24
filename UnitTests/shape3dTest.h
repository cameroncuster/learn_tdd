#ifndef SHAPE3DTEST_H
#define SHAPE3DTEST_H

#include "pointTest.h"

class Shape3dTest
{
protected:
   PointTest location;   // this is the center of the 3d shape
   std::string typeName;
public:
   Shape3dTest(PointTest &l, std::string);
   virtual bool contains(const PointTest&) const = 0;
   virtual double volume() const = 0;
   std::string type();

   friend std::ostream& operator<<(std::ostream& os, const Shape3dTest *obj);
};

#endif
