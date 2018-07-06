#include <iostream>
using std::cout;
using std::endl;

#include "Human.h"

int main()
{
	//local scoped, implicitly ints.. cast to use
	enum class Hair
	{
		Straight,
		Curly,
		None
	};
	Hair pubic = Hair::Curly;
	
	return 0;
}
