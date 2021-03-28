#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "point.h"
#include "ellipsoid.h"

using namespace std;

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
   if (argc > 1) 
   {
      string str(argv[1]);
      numPoints = stoi(str);
   }

   Point ellipsoidCenter(0.5, 0.5, 0.5);
   Ellipsoid ellipsoid(ellipsoidCenter, 0.5, 0.35, 0.25);

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
