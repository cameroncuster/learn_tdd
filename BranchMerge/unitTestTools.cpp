#include "unitTestTools.h"

using namespace std;

vector<double> randCoord( const int bound )
{
	srand( time( NULL ) );
	int i;
	double c;
	vector<double> coord( 3 );
	for( i = 0; i < 3; i++ )
	{
		c = rand( ) % bound;
		c += 1 / ( ( rand( ) % bound ) + 1 );
		coord[i] = c;
	}
	return coord;
}

pair<Point, PointTest> constructRandomPointPair( const int bound )
{
	vector<double> coord = randCoord( bound );
	Point p( coord[0], coord[1], coord[2] );
	PointTest pTest( coord[0], coord[1], coord[2] );
	return { p, pTest };
}

bool operator==( Point &lhs, PointTest &rhs )
{
	return ( lhs.xLoc == rhs.xLoc && lhs.yLoc == rhs.yLoc && rhs.zLoc == lhs.zLoc );
}
