#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <algorithm>
using std::for_each;
using std::transform;
using std::back_inserter;
//using std::generate_n;
#include <vector>
using std::vector;

int main()
{
	vector<int> v {0,1}; //curly init
	int control = 2;
	v.push_back(control);
//begin, end, print lamda
	for_each(v.begin(), v.end(),
		[](int i) //lamda, capture clause
			{
				i%2==0 ?
				cout << i << " Even" << endl :
				cout << i << " Odd" << endl;
			}
	);
	vector<int> v2;
	transform(v.begin(), v.end(), back_inserter(v2),
		[control](int i) mutable -> int
			{
				i%2==0? control = 5 : control = 1;
				return i*i*control;
			}
	);
		for_each(v2.begin(), v2.end(),
		[](int i) //lamda
			{
				cout << i << endl;
			}
	);
	return 0;
}
