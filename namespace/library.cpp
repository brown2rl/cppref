#include "API.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	if(API::v1::oldfunc(true))
	{
		cout << "version 1" << endl;
	}
	if(API::newfunc(true))
	{
		cout << "version 2" << endl;
	}
	return 0;
}
