#include "../catch/catch.hpp"
#include "cube.h"
#include "ellipsoid.h"
#include "point.h"
#include "prism.h"
#include "shape3d.h"
#include "sphere.h"
#include <sstream>
#include <iostream>

using namespace std;
using std::ostringstream;

TEST_CASE("Test input of points in to the system and << operator")
{
    ostringstream sout;
    Point p(1, 1, 1);
    Point p1(1, 2, 3);
    Point p2(10, 12, 24);
    Point p3(250.1, 123.12, 15.3);

    SECTION("Basic point 1,1,1")
    {
        sout << p;
        REQUIRE(sout.str() == "[1, 1, 1]");
        sout.str("");
    }

    SECTION("Mixed Point 1,2,3")
    {
        sout << p1;
        REQUIRE(sout.str() == "[1, 2, 3]");
        sout.str("");
    }

    SECTION("Mid Size Mixed Points 10,12,24")
    {
        sout << p2;
        REQUIRE(sout.str() == "[10, 12, 24]");
        sout.str("");
    }

    SECTION("Mix Points with Decimals 250.1, 123.12, 15.3")
    {
        sout << p3;
        REQUIRE(sout.str() == "[250.1, 123.12, 15.3]");
        sout.str("");
    }
}

TEST_CASE("Test '-' operator for point")
{
    ostringstream sout;
    Point p(1, 1, 1);
    Point p1(1, 2, 3);
    Point p2(10, 12, 24);
    Point p3(250.1, 123.12, 15.3);

    SECTION("Test points(1,2,3) - (1,1,1)")
    {
        Point result = p1 - p;
        sout << result;
        REQUIRE(sout.str() == "[0, 1, 2]");
        sout.str("");
    }
    SECTION("Test point(10,12,24) - (1,2,3)")
    {
        Point result = p2 - p1;
        sout << result;
        REQUIRE(sout.str() == "[9, 10, 21]");
        sout.str("");
    }
    SECTION("Test point(250.1,123.12,15.3) - (10,12,24)")
    {
        Point result = p3 - p2;
        sout << result;
        REQUIRE(sout.str() == "[240.1, 111.12, -8.7]");
        sout.str("");
    }
}

TEST_CASE("Test distance function for point")
{
    ostringstream sout;
    Point p(1, 1, 1);
    Point p1(1, 2, 3);
    Point p2(10, 12, 24);
    Point p3(250.1, 123.12, 15.3);

    SECTION("Distance between (1,2,3) to (1,1,1)")
    {
        double result = p1.distance(p);
        REQUIRE(abs(result - 2.23606) <= .0002);
    }
    SECTION("Distance between (1,1,1) to (1,2,3)")
    {
        double result = p.distance(p1);
        REQUIRE(abs(result - 2.23606) <= .0002);
    }
    SECTION("Distance between (1,1,1) to (10,12,24)")
    {
        double result = p.distance(p2);
        REQUIRE(abs(result - 27.037012) <= .0002);
    }
    SECTION("Distance between (1,1,1) to (250.1,123.12,15.3)")
    {
        double result = p.distance(p3);
        REQUIRE(abs(result - 277.792358) <= .0002);
    }
    SECTION("Distance between (1,2,3) to (10,12,24)")
    {
        double result = p1.distance(p2);
        REQUIRE(abs(result - 24.939928) <= .0002);
    }
    SECTION("Distance between (1,2,3) to (250.1,123.12,15.3)")
    {
        double result = p1.distance(p3);
        REQUIRE(abs(result - 277.258281) <= .0002);
    }
    SECTION("Distance between (1,1,1) and (1,1,1)")
    {
        double result = p.distance(p);
        REQUIRE(result == 0);
    }
}

TEST_CASE("Test of the shape3d function")
{
    Point p1(1, 1, 1);

    SECTION("Shape type = Cube with only point" ) 
    {
        Cube cubeTest(p1);
        REQUIRE(cubeTest.type() == "Cube");
    }

    SECTION("Shape type = Cube with point and lenght" ) 
    {  
        Cube cubeTest(p1, 1.0);
        REQUIRE(cubeTest.type() == "Cube");
    }

    SECTION("Shape type = Prism with only point" ) 
    {
        Prism prismTest(p1);
        REQUIRE(prismTest.type() == "Prism");
    }

    SECTION("Shape type = Prism with point and dimensions" ) 
    {
        Prism prismTest(p1, 1.0, 1.0, 1.0);
        REQUIRE(prismTest.type() == "Prism");
    }

    SECTION("Shape type = Ellipsoid" ) 
    {
        Ellipsoid ellipsoidTest(p1, 1.0, 1.0, 1.0);
        REQUIRE(ellipsoidTest.type() == "Ellipsoid");
    }

    SECTION("Shape type = Sphere with only point" ) 
    {
        Sphere sphereTest(p1);
        REQUIRE(sphereTest.type() == "Sphere");
    }

    SECTION("Shape type = Sphere with both point and radius" ) 
    {
        Sphere sphereTest(p1, 1.0);
        REQUIRE(sphereTest.type() == "Sphere");
    }
}

TEST_CASE("Test cube functions")
{
    ostringstream sout;
    Point p(1, 1, 1);
    Point p1(1, 2, 3);
    Point p2(10, 12, 24);
    Point p3(250.1, 123.12, 15.3);
    Point p4(-1.5, 1.5, 1.7);
    Point p5(0, 0, 0);
    Point p6(-1, 0, 0);
    Point p7(0.5, 0.5, 0.5);
    Point p8(2, 2, 2);
    Point p9(-4, -3, -2);
    Point p10(4, -3.4, -2.7);
    Point p11(2.2, -4, -5);

    SECTION("Build cube with (1,2,3) points testing to see (1,1,1) not included")
    {
        Cube cube(p1, 2.0);
        REQUIRE(cube.contains(p) == false);
    }

    SECTION("Build cube with (1,1,1) points testing to see (1,2,3) is included")
    {
        Cube cube(p, 4.0);
        REQUIRE(cube.contains(p1) == true);
    }

    SECTION("Build cube with (10,12,24) points testing to see (250.1,123.12,15.3) not included")
    {
        Cube cube(p2, 250.0);
        REQUIRE(cube.contains(p3) == false);
    }

    SECTION("Build cube with (10,12,24) points testing to see (10,12,24) is included")
    {
        Cube cube(p2, 250.0);
        REQUIRE(cube.contains(p2) == true);
    }
    SECTION("Verify that the default values provided operates for volume")
    {
        Cube cube(p5);
        REQUIRE(cube.volume() == 1.0);
    }
    SECTION("Cube of lenght 1000 with center (2,2,2) contains (4,-3.4,-2.7)")
    {
        Cube cube(p11, 1000);
        REQUIRE(cube.contains(p10) == true);
    }
    SECTION("Volume of Cube with 0 length and point (0,0,0)")
    {
        Cube cube(p5, 0);
        REQUIRE(cube.volume() == 0);
    }
    SECTION("Volume of Cube with 1 length and point (1,1,1)")
    {
        Cube cube(p, 1);
        REQUIRE(cube.volume() == 1);
    }
    SECTION("Volume of Cube with 0 lenght and point (-1,0,0)")
    {
        Cube cube(p6, 0);
        REQUIRE(cube.volume() == 0);
    }
    SECTION("Volume of Cube with 1.5 length and (-1.5, 1.5, 1.7)")
    {
        Cube cube(p4, 1.5);
        REQUIRE(cube.volume() == 3.375);
    }
    SECTION("Test that contains shouldn't change the point's value")
    {
        Cube cube(p4, 1.5);
        REQUIRE(cube.contains(p5) == false);
        REQUIRE(p4.distance(p4) == 0);
        REQUIRE(p5.distance(p5) == 0);
    }
}

TEST_CASE("Test of the ellipsoid functions")
{
    SECTION("Test of point in the bound of an ellipsoid")
    {
        Point p0(0, 0, 0);
        Point p1(8, 8, 8);
        Point p2(0.1, 0.1, 0.1);
        Point p3(8.1, 8.1, 8.1);
        Point p4(0.9, 0, 0);
        Point p5(0, 1.9, 0);
        Point p6(0, 0, 2.9);
        Point p7(8.9, 8, 8);
        Point p8(8, 9.9, 8);
        Point p9(8, 8, 10.9);

        Ellipsoid ellipse(p0, 1, 2, 3);
        Ellipsoid ellipse8(p1, 1, 2, 3);

        REQUIRE(ellipse.contains(p2) == true);
        REQUIRE(ellipse.contains(p4) == true);
        REQUIRE(ellipse.contains(p5) == true);
        REQUIRE(ellipse.contains(p6) == true);
        REQUIRE(ellipse8.contains(p3) == true);
        REQUIRE(ellipse8.contains(p7) == true);
        REQUIRE(ellipse8.contains(p8) == true);
        REQUIRE(ellipse8.contains(p9) == true);
    }

    SECTION("Test of point on the bounds of an ellipsoid")
    {
        Point p0(0, 0, 0);
        Point p1(1, 0, 0);
        Point p2(0, 2.2, 0);
        Point p3(0, 0, 3.42);
        Point p4(-1, 0, 0);
        Point p5(0, -2.2, 0);
        Point p6(0, 0, -3.42);

        Ellipsoid ellipse(p0, 1, 2.2, 3.42);

        REQUIRE(ellipse.contains(p1) == true);
        REQUIRE(ellipse.contains(p2) == true);
        REQUIRE(ellipse.contains(p3) == true);
        REQUIRE(ellipse.contains(p4) == true);
        REQUIRE(ellipse.contains(p5) == true);
        REQUIRE(ellipse.contains(p6) == true);
    }

    SECTION("Testing of points outside of the bounds of an ellipsoid")
    {
        Point p0(0.05, 0.05, 0.05);
        Point p1(2, 2, 2);
        Point p2(0.56, 0.5, 0.5);
        Point p3(0.5, 0.76, 0.5);
        Point p4(0.5, 0.5, 0.86);

        Ellipsoid ellipse(p0, 0.5, 0.7, 0.8);

        REQUIRE(ellipse.contains(p1) == false);
        REQUIRE(ellipse.contains(p2) == false);
        REQUIRE(ellipse.contains(p3) == false);
        REQUIRE(ellipse.contains(p4) == false);
    }

    SECTION("Volume of an ellipse with various radidius")
    {
        Point p(0, 0, 0);

        Ellipsoid ellipse1(p, 2, 3.14, 16);
        Ellipsoid ellipse2(p, 1.5, 2.76583, 84);

        REQUIRE(ellipse1.volume() == (4.0 / 3.0) * M_PI * 2 * 3.14 * 16);
        REQUIRE(ellipse2.volume() == (4.0 / 3.0) * M_PI * 1.5 * 2.76583 * 84);
    }
}

TEST_CASE("Test of the Prism Functions")
{
    Point p1(-1, -2, -3);
    Point p2(1.3, -1.8, -7.4);
    Point p3(0, 0, 0);
    Point p4(-1.5, 1.5, 1.7);
    Point p5(1, 1, 1);
    Point p6(1.1, 1.1, 1.1);
    Point p7(2.1, -2.6, -6.2);
    Point p8(-3.8, 4.5, -7.1);

    SECTION("Verify that the constructor and volume works with a negative point")
    {
        Prism prism(p1, 5, 7, 1);
        REQUIRE(prism.volume() == 35.0);
    }

    SECTION("Verify that decimal points/values and volume works")
    {
        Prism prism(p2, 8.5, 6.3, 0.9);
        REQUIRE(prism.volume() == 48.195);
    }

    SECTION("Verify that the default values return a volume of 1")
    {
        Prism prism(p3);
        REQUIRE(prism.volume() == 1.0);
    }

    SECTION("Verify that volume shouldn't change the class")
    {
        Prism prism(p4);
        REQUIRE(prism.volume() == 1.0);
        REQUIRE(p4.distance(p4) == 0);
    }

    SECTION("Verify that contains doesn't change the point value")
    {
        Prism prism(p4);
        REQUIRE(prism.contains(p3) == false);
        REQUIRE(p4.distance(p4) == 0);
        REQUIRE(p3.distance(p3) == 0);
    }

    SECTION("Verify that decimal values work for the Prism Volume")
    {
        Prism prism(p5 , 1.8,2,3);
        REQUIRE(prism.volume()==10.8);
    }

    SECTION("Verify that zero prism volume works")
    {
        Prism prism (p3, 0,0,0);
        REQUIRE(prism.volume() == 0.0);
        REQUIRE(prism.contains(p3) == true);
    }

    SECTION ("Verify that the contains has a decimal value for a point")
    {
        Prism prism(p5,1,1,1);
        REQUIRE(prism.contains(p6) == true);
    }

    SECTION ("Verify that teh contains can handel 2 negiative points")
    {
        Prism prism(p7, 2,2,2);
        REQUIRE(prism.contains(p8) == false);
    }
}


TEST_CASE ("Check sphere function")
{
    SECTION ("Checking points are in bounds of a sphere")
    {
        Point p(0,0,0);
        Point p1(0.1,0.1,0.1);
        Point p2(0.9,0,0);

        Sphere sphere (p);

        REQUIRE (sphere.contains(p1) == true);
        REQUIRE (sphere.contains(p2) == true);
    }

    SECTION ("Check for point on the bounds of a sphere")
    {
        Point p(0,0,0);
        Point p1(1,0,0);
        Point p2(0,1,0);
        Point p3(0,0,1);
        Point p4(-1,0,0);
        Point p5(0,-1,0);
        Point p6(0,0,-1);

        Sphere sphere (p);

        REQUIRE (sphere.contains(p1) == true);
        REQUIRE (sphere.contains(p2) == true);
        REQUIRE (sphere.contains(p3) == true);
        REQUIRE (sphere.contains(p4) == true);
        REQUIRE (sphere.contains(p5) == true);
        REQUIRE (sphere.contains(p6) == true);
    }

    SECTION ("Check for points outside the bounds of the sphere")
    {
        Point p(0,0,0);
        Point p1(2,2,2);
        Point p2(1.1,0,0);

        Sphere sphere (p);

        REQUIRE (sphere.contains(p1) == false);
        REQUIRE (sphere.contains(p2) == false); 
    }

    SECTION ("Volume of a sphere with  a default radius")
    {
        Point p(0,0,0);
        Point p1(1,1,1);

        Sphere sphere1 (p);
        Sphere sphere2 (p1);

        REQUIRE(sphere1.volume() == (4.0/3) * 3.14159);
        REQUIRE(sphere2.volume() == (4.0/3)*3.14159);
    }

    SECTION ("Volume of a sphere with alternate radius")
    {
        Point p(0,0,0);
        Point p1(1,1,1);

        Sphere sphere1 (p,2);
        Sphere sphere2(p,1.5);
        Sphere sphere3(p1, 3);
        Sphere sphere4 (p1, 105.232322323);

        REQUIRE (sphere1.volume() == (4.0/3)*3.14159*2*2*2);
        REQUIRE (sphere2.volume() == (4.0/3)*3.14159*1.5*1.5*1.5);
        REQUIRE (sphere3.volume() == (4.0/3)*3.14159*3*3*3);
        REQUIRE (sphere4.volume() == (4.0/3)*3.14159*105.232322323*105.232322323*105.232322323);
    
    }
}