#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	vector<int> a { 1,2,3,2,2 };
// how many 2's
	int count = std::count(begin(a), end(a), 2);
	cout << count << endl;
//1-true, 0-false count if 2's in a
	auto  isA = count_if(begin(a), end(a),
		[](auto element){ return element=='a'? true: false; });
	cout << isA << endl;
//all_of(begin,end,lamda condition)
//none_of(begin,end,lamda)
//any_of(begin,end,lamda)
//find 
//find_if_not
//find_first_of(begin,end,begin(comparisonval),end(comparisonval))
//search(begin,end,begin(subsequence),end(subsequence))
//find_end(begin,end,begin(subsequence),end(subsequence))
//search_n(begin,end,numofoccurences,value) - consecutive sequence
//adjacent_find(begin,end) - consecutive values
	auto res = find(begin(a), end(a), 3);
	int lookedfor = *res;
	cout << lookedfor << endl;
	return 0;
}
