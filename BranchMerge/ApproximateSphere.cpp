#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "point.h"
#include "sphere.h"

using namespace std;

// By default use 10 million points to approximate volume
#define POINTS_TO_GENERATE 10000000

// Generate a point ([0.0,1.0], [0.0,1.0], [0.0,1.0])
// Remember your interval notation!
Point genPoint()
{
   Point p((double)rand()/RAND_MAX,
           (double)rand()/RAND_MAX,
           (double)rand()/RAND_MAX);
   return p;
}

int main(int argc, char *argv[])
{
   int pointsContained = 0;
   int numPoints = POINTS_TO_GENERATE;

   // If the user enters number of points on command line, use that
   if (argc > 1)
   {
      string str(argv[1]);
      numPoints = stoi(str);
   }

   Point sphereCenter(0.5, 0.5, 0.5);
   Sphere sphere(sphereCenter, 0.5);

   // Seed the pseudo-random number generator
   srand(time(NULL));

   // Generate the points and calculate containment
   for (int i = 0 ; i < numPoints ; i++)
      if (sphere.contains(genPoint()))
         pointsContained++;

   double estimate = (double)pointsContained / (double)numPoints;
   cout << "Estimated Volume  = " << estimate << endl;
   cout << "Calculated Volume = " << sphere.volume() << endl;
   cout << "Accuracy = " << (1.0-(fabs(estimate-sphere.volume()) / sphere.volume())) * 100.0 << "%" << endl;
   return 0;

   //As per the assignment task this is the appropriate file, which was provided
}
