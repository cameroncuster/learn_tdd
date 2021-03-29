#include "../catch.hpp"
#include "point.h"
#include "shape3d.h"
#include "prism.h"

TEST_CASE("Initial Test")
{
    
}

TEST_CASE("Find the origin of a prism with x, y, and z sidelengths of (1, 2, 1) centered at (0, 0, 0)", "[prism]")
{
    Point origin = Point(0.0, 0.0, 0.0);
    double x = 1.0;
    double y = 2.0;
    double z = 1.0;

    Prism prism(origin, x, y, z);
    
    auto result = prism.contains(origin);

    REQUIRE(result == true);
}

TEST_CASE("Find the boundary point (0, 0, 0.5) of a prism with x, y, and z sidelengths of (1, 2, 1) centered at (0, 0, 0)", "[prism]")
{
    Point origin = Point(0.0, 0.0, 0.0);
    Point testPoint = Point(0.0, 0.0, 0.5);
    double x = 1.0;
    double y = 2.0;
    double z = 1.0;

    Prism prism(origin, x, y, z);
    
    auto result = prism.contains(testPoint);

    REQUIRE(result == true);
}

TEST_CASE("Find the point (0, 0, 0.5 - 0.01) of a prism with x, y, and z sidelengths of (1, 2, 1) centered at (0, 0, 0)", "[prism]")
{
    Point origin = Point(0.0, 0.0, 0.0);
    Point testPoint = Point(0.0, 0.0, 0.5 - 0.01);
    double x = 1.0;
    double y = 2.0;
    double z = 1.0;

    Prism prism(origin, x, y, z);
    
    auto result = prism.contains(testPoint);

    REQUIRE(result == true);
}

TEST_CASE("Test the point (0, 0, 0.51) of a prism with x, y, and z sidelengths of (1, 2, 1) centered at (0, 0, 0) to make sure it's outside the prism", "[prism]")
{
    Point origin = Point(0.0, 0.0, 0.0);
    Point testPoint = Point(0.0, 0.0, 0.51);
    double x = 1.0;
    double y = 2.0;
    double z = 1.0;

    Prism prism(origin, x, y, z);
    
    auto result = prism.contains(testPoint);

    REQUIRE(result == false);
}

TEST_CASE("Find the volume of a prism with x, y, and z sidelengths of (1, 2, 1)", "[prism]")
{
    Point origin = Point(0, 0, 0);
    double x = 1.0;
    double y = 2.0;
    double z = 1.0;

    Prism prism(origin, x, y, z);
    
    double volume = x * y * z;
    auto result = prism.volume();

    REQUIRE(result == volume);
}

TEST_CASE("Find the volume of a prism with x, y, and z sidelengths of (10000000, 20000000, 10000000)", "[prism]")
{
    Point origin = Point(0, 0, 0);
    double x = 10000000.0;
    double y = 20000000.0;
    double z = 10000000.0;

    Prism prism(origin, x, y, z);
    
    double volume = x * y * z;
    auto result = prism.volume();

    REQUIRE(result == volume);
}
