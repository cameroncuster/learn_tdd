#include "pointTest.h"

PointTest::PointTest(double x, double y, double z) : xLoc(x), yLoc(y), zLoc(z) {}

std::ostream& operator<<(std::ostream& os, const PointTest &p)
{
	os << "[" << p.xLoc << ", " << p.yLoc << ", " << p.zLoc << "]";
	return os;
}

PointTest PointTest::operator-(const PointTest & rhs) const
{
	PointTest result(xLoc - rhs.xLoc, yLoc - rhs.yLoc, zLoc - rhs.zLoc);
	return result;
}

double PointTest::distance(const PointTest &p) const
{
	return sqrt(pow(xLoc - p.xLoc, 2) + pow(yLoc - p.yLoc, 2) +
			pow(zLoc - p.zLoc, 2));
}
