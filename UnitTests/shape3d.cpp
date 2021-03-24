#include "shape3d.h"

Shape3d::Shape3d(Point &p, std::string name) : location(p), typeName(name) {}

std::ostream& operator<<(std::ostream& os, const Shape3d *obj)
{
   os << obj->location;
   return os;
}

std::string Shape3d::type() { return typeName ; }
