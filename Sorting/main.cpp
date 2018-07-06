#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math>
#include <random>

using namespace std;

int main()
{
	vector<int> a { 1,2,-3,2,2 };
	//vector
	auto a2=a;
	sort(begin(a), end(a), [](int e1, int e2){return e1 > e2});
	sort(begin(a), end(a), [](int e1, int e2){return abs(e1) > abs(e2)});
//stable_sort(begin,end,lamda) - sort, then sort again by another prop
//upper_bound(begin,end,value) - on sorted collection
//lower_bound(begin,end,value) - "
//partial_sort(begin,find(begin,end,beginnonsortvalue),end) - for userbased sorting on large collection
//is_sorted_until
//vector <int> v(3); 
//partial_sort_copy(begin,end,begin(v),end(v))
//nth_element(begin,begin+shiftval, end) - val of median if sorted
random_device randomdevice;
mt19937 generator(randomdevice());
shuffle(begin(a),end(a),generator);

	
	return 0;
}
