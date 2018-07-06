#include <iostream>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::set;

int main()
{
	auto a = set<int> {0,2,3,4,5};
// binary search for upper & lower bounds based on key of 3
	auto upper = a.upper_bound(3); // excluding 3
	auto lower = a.lower_bound(3); // exlcuding 3
// one pass w/ including upper and lower bounds
//	auto range = c.equal_range(3);
	cout << "\nfirst half" << endl;
	for (auto i = begin(a); i != lower; i++)
	{
		cout << *i << endl;
	}
	cout << "\nsecond half" << endl;
	for (auto i = upper; i != end(a); i++)
	{
		cout << *i << endl;
	}
	cout << "\nordered" << endl;
	for (auto v:a)
	{
		if(v == 0) { a.insert(1);}
		cout << v << endl;
	}
	return 0;
}
