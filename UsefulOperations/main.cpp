#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	/*
swapping: any 2 refs of same type, iterators, ranges
 */
vector <int> evens { 2,4,6,8,10};
vector <int> odds { 1,3,5,7,9 };

auto v1 = evens;
swap(v1[0],v1[1]);
iter_swap(begin(v1), begin(v1)+1);

auto v2 = odds;
iter_swap(begin(v1), find(begin(v2), end(v2), 5);

v1 = evens;
v2 = odds;

swap_ranges(begin(v1),  find(begin(v2), end(v2), 6), begin(v2)); // excluding 6
/*
rotating: moving elemnts to new position.. (first, newfirst, last)
rotate_copy(first, newfirst, last, destfirst)
*/
vector<int> tasks(6);
iota(begin(tasks), end(tasks), 1);
auto two = std::find(begin(tasks), end(tasks), 2);
auto four = std::find(begin(tasks), end(tasks), 4);
rotate(two, four, four+1);
/*
partitioning: gather based oupon a lmada, stable - in order and regular/unsorted
*/
vector<int> num(8);
iota(begin(num), end(num), 1);
auto selected = std::stable_partition(begin(num), end(num), [](int i) { return i % 2; });
four = std::find(begin(num), end(num), 4);
rotate(begin(num), selected, four);
// can use stable_partition+rotate

//inplace_merge(first, middle, last)
	return 0;
}
