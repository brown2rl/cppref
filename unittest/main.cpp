#define CATCH_CONFIG_MAIN	

#include "catch.hpp"

#include "MyClass.h"
#define CASE TEST_CASE

//macro
	//[tag1][tag2] -- group tests by type, speed, etc.
	//[.itegration] - explicit integration tag	
	//[!hide] or [.] - skip
	//[!mayfail] - doesn't fail test for failed assertions

// disable execution
CASE("Function() return 50","[int][arbitrary]")
{
	MyClass myClass;

	REQUIRE(myClass.function()==50);
}
// allow excecution
CASE("should display catch2 flag options","[helps]")
{
	MyClass myClass;
	
	REQUIRE(myClass.flags()==0);
}
CASE("sections can be nested, but be careful")
{
	MyClass myClass2;
	SECTION("section 1 --> function() should return int 50")
	{
		REQUIRE(myClass2.function()==50);
	}
	SECTION("section 2 --> should fail with assertion of 10")
	{
		REQUIRE(myClass2.function()==10);
	}
}
// exception tests (passes for exceptions)
/*
REQUIRE_THROWS( expression )
CHECK_THROWS( expression )
REQUIRE_THROWS_AS( expression, type )
CHECK_THROWS_AS( expression, type )
REQUIRE_NOTHROW( expression )
CHECK_NOTHROW( expression )
*/

// logging contextual info

/*
INFO( "" ) - shown on fail
WARN ( "" << value ) - shown pass/fail
FAIL ( "" ) - always show and will fail the test
CAPTURE( someval ) - like info, but with var name & values
*/

// logical test alternatives
/*
TEST_CASE_METHOD( customFixture, ["tag"] )
*/


