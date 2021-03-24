#include "unitTestTools.h"

using namespace std;

TEST_CASE( "Prism Contains and Volume Methods Comparison Tested with Random Values" )
{
	int i;
	vector<double> dim;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p = constructRandomPointPair( bound );
		pair<Point, PointTest> loc = constructRandomPointPair( bound );
		dim = randCoord( bound );
		Prism pr( p.first, dim[0], dim[1], dim[2] );
		PrismTest prTest( p.second, dim[0], dim[1], dim[2] );

		REQUIRE( pr.volume( ) == prTest.volume( ) );
		REQUIRE( pr.contains( loc.first ) == prTest.contains( loc.second ) );
	}
}
