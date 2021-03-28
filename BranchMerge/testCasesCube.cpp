#include "unitTestTools.h"

using namespace std;

TEST_CASE( "Cube Contains and Volume Methods Comparison Tested with Random Values" )
{
	srand( time( NULL ) );
	int i;
	double l;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p = constructRandomPointPair( bound );
		pair<Point, PointTest> loc = constructRandomPointPair( bound );
		l = rand( ) % bound;
		l += 1 / ( ( rand( ) % bound ) + 1 );
		Cube c( p.first, l );
		CubeTest cTest( p.second, l );

		REQUIRE( c.volume( ) == cTest.volume( ) );
		REQUIRE( c.contains( loc.first ) == cTest.contains( loc.second ) );
	}
}
