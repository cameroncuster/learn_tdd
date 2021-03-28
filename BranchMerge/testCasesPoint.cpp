#include "unitTestTools.h"

using namespace std;

TEST_CASE( "Point Constructor Comparison Tested with Random Values" )
{
	int i;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p = constructRandomPointPair( bound );

		REQUIRE( p.first == p.second );
	}
}

TEST_CASE( "Point Distance Comparison Tested with Random Values" )
{
	int i;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p1 = constructRandomPointPair( bound );
		pair<Point, PointTest> p2 = constructRandomPointPair( bound );

		REQUIRE( p1.first.distance( p2.first ) == p1.second.distance( p2.second ) );
		REQUIRE( p2.first.distance( p1.first ) == p2.second.distance( p1.second ) );
	}
}

TEST_CASE( "Point operator( - ) Comparison Tested with Random Values" )
{
	int i;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p1 = constructRandomPointPair( bound );
		pair<Point, PointTest> p2 = constructRandomPointPair( bound );

		pair<Point, PointTest> p3 = { p2.first - p1.first, p2.second - p1.second };

		REQUIRE( p3.first == p3.second );
	}
}

TEST_CASE( "Point operator( << ) Comparison Tested with Random Values" )
{
	int i;
	stringstream sout;
	stringstream soutTest;
	for( i = 0; i < capacity; i++ )
	{
		pair<Point, PointTest> p1 = constructRandomPointPair( bound );
		pair<Point, PointTest> p2 = constructRandomPointPair( bound );

		sout << p1.first << p2.first;
		soutTest << p1.second << p2.second;

		REQUIRE( sout.str( ) == soutTest.str( ) );
	}
}
