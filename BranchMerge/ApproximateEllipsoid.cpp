#include <cstdlib>
#include <ctime>
#include <cmath>
#include "point.h"
#include "ellipsoid.h"
#include <iostream>
#define POINTS_TO_GENERATE 10000000

using namespace std;

// FIXME: Only generating volume of 1
Point genPoint()
{
    // Generate random numbers between 0 and 7
    unsigned int diceNum = rand() % 8;

    if(diceNum == 0)
    {
        Point p((double)rand(), (double)rand(), (double)rand());
        return p;
    }

    else if(diceNum == 1)
    {
        // Subtracting RAND_MAX / 2 negates the number
        Point p((double)rand(), (double)rand(), (double)rand() * -1);
        return p;
    }

    else if(diceNum == 2)
    {
        Point p((double)rand(), (double)rand() * -1, (double)rand() * -1);
        return p;
    }

    else if(diceNum == 3)
    {
        Point p((double)rand() * -1, (double)rand() * -1, (double)rand() * -1);
        return p;
    }

    else if(diceNum == 4)
    {
        Point p((double)rand() * -1, (double)rand(), (double)rand());
        return p;
    }

    else if(diceNum == 5)
    {
        Point p((double)rand() * -1, (double)rand() * -1, (double)rand());
        return p;
    }

    else if(diceNum == 6)
    {
        Point p((double)rand() * -1, (double)rand(), (double)rand() * -1);
        return p;
    }

    // diceNum == 7
    else
    {
        Point p((double)rand(), (double)rand() * -1, (double)rand());
        return p;
    }
}

int main(int argc, char *argv[])
{
   unsigned int pointsContained = 0;
   unsigned int numPoints = POINTS_TO_GENERATE;
   unsigned int xrad = 0;
   unsigned int yrad = 0;
   unsigned int zrad = 0;
   int xcoor = 0;
   int ycoor = 0;
   int zcoor = 0;

   // argv[1] is the amount of points entered on the command
   // line, default is 10000000
   if (argc > 1)
   {
      string str(argv[1]);
      numPoints = stoi(str);
   }

    cout << "Enter x radius: ";
    cin >> xrad;

    cout << "Enter y radius: ";
    cin >> yrad;

    cout << "Enter z radius: ";
    cin >> zrad;
    cout << endl;

    cout << "Enter x coordinate for center: ";
    cin >> xcoor;

    cout << "Enter y coordinate for center: ";
    cin >> ycoor;

    cout << "Enter z coordinate for center: ";
    cin >> zcoor;
    cout << endl;

    Point ellipsoidCenter(xcoor, ycoor, zcoor);


    // Ellipsoid(Point &p, double xrad, double yrad, double zrad);
    Ellipsoid ellipsoid(ellipsoidCenter, xrad, yrad, zrad);

    // Seed pseudo-random generator
    srand(time(NULL));

    // Generate random points and decide on containment
    for (int i = 0 ; i < numPoints ; i++)
        if (ellipsoid.contains(genPoint()))
            pointsContained++;

    double estimate = (double)pointsContained / (double)numPoints;
    cout << "Estimated Volume  = " << estimate << endl;
    cout << "Calculated Volume = " << ellipsoid.volume() << endl;
    cout << "Accuracy = " << (1.0-(fabs(estimate-ellipsoid.volume()) / ellipsoid.volume())) * 100.0 << "%" << endl;
    return 0;
}
