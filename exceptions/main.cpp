#include <iostream>
using std::cout;
#include <string>
using std::string;
using std::endl;
#include "Poly.h"

int main()
{
	try { // objects must have destructors called before error thrown.. smart pointers, etc.
		Poly triangle("triangle", 3);
		cout << triangle.Info() << endl;
		Poly line("line", 1);
	} catch (exception& e){ //caught by ref
		cout << e.what() << endl; //message
	}
	return 0;
}
