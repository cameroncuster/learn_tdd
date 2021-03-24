#include "shape3dTest.h"

Shape3dTest::Shape3dTest(PointTest &p, std::string name) : location(p), typeName(name) {}

std::ostream& operator<<(std::ostream& os, const Shape3dTest *obj)
{
   os << obj->location;
   return os;
}

std::string Shape3dTest::type() { return typeName ; }
