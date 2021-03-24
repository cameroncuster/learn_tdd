#include "unitTestTools.h"

using namespace std;

TEST_CASE( "Ellipsoid Contains and Volume Methods Comparison Tested with Random Values" )
{
	int i;
	vector<double> rad;
	// default construct ellipsoid
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p = constructRandomPointPair( bound );
		pair<Point, PointTest> loc = constructRandomPointPair( bound );
		rad = randCoord( bound );
		Ellipsoid e( p.first, rad[0], rad[1], rad[2] );
		EllipsoidTest eTest( p.second, rad[0], rad[1], rad[2] );

		REQUIRE( e.volume( ) == eTest.volume( ) );
		REQUIRE( e.contains( loc.first ) == eTest.contains( loc.second ) );
	}
}
