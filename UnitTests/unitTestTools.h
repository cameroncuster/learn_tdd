#include "../catch/catch.hpp"
#include "point.h"
#include "pointTest.h"
#include "cube.h"
#include "cubeTest.h"
#include "ellipsoid.h"
#include "ellipsoidTest.h"
#include "prism.h"
#include "prismTest.h"
#include "sphere.h"
#include "sphereTest.h"

using namespace std;

const constexpr int capacity = 9001;
const constexpr int bound = 900001;

vector<double> randCoord( const int );
pair<Point, PointTest> constructRandomPointPair( const int );
bool operator==( Point &lhs, PointTest &rhs );
