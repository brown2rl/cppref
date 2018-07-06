#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	vector<int> a { 1,2,3,2,2 };
	vecot<int> b { 1,2,3 };
	bool same = equal(begin(a),end(a),begin(b),end(b));
//std::pair - any strongly type.. .first, .second
	auto firstchange = mismatch(begin(a),end(a),begin(b));
	int avalue = *(firstchange.first);
	int bvalue = *(firstchange.second);
	// accumulate(begin,end,startvalue,[lamda]) - sum elements of a collection (+ operator)
	int total = accumulate(begin(a),end(a), 0);
	//for_each(iterator, iterator, lamda)
	auto firstthree = find(begin(a),end(b),3);
	for_each(firstthree, end(b), [](int& element){ element = 0;});
	return 0;
}
