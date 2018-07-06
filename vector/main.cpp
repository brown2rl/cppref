#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Person.h"

int main()
{
	vector<Person> v;
	Person a("Rob",29);
	Person b("Joe",30);
	Person c("Mark",28);

	/*Person* ap = &a;
	Person* bp = &b;
	Person* cp = &c; */

	v.push_back(a); v.push_back(b); v.push_back(c);

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << i->Info() << endl;
	}
//reverse access
	for (auto i = v.rbegin(); i != v.rend(); i++)
	{
		cout << i->Info() << endl;
	}

	return 0;
}
