#include "unitTestTools.h"

using namespace std;

TEST_CASE( "Sphere Contains and Volume Methods Comparison Tested with Random Values" )
{
	srand( time( NULL ) );
	int i;
	double r;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p = constructRandomPointPair( bound );
		pair<Point, PointTest> loc = constructRandomPointPair( bound );
		r = rand( ) % bound;
		Sphere s( p.first, r );
		SphereTest sTest( p.second, r );

		REQUIRE( s.volume( ) == sTest.volume( ) );
		REQUIRE( s.contains( loc.first ) == sTest.contains( loc.second ) );
	}
}
