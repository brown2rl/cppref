#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	vector<int> a { 1,2,3,-2,2 };
	vector<int> b { 1,2,3 };
	/*
copying: operator=, loops, copy(), copy_if(), copy_n(),copy_backward()
*/
vector<int> a1(a.size());
copy(begin(a), end(a), begin(a1));

auto a2 = a; // entire collection

auto position = find(begin(a), end(a), -2);
vector<int> a3(a.size());
copy(begin(a), position+1, begin(a3)); //inclusive

vector<int> a4(a.size());
copy_if(begin(a), end(a), begin(a4), // copy elements w/ even values
  [](int element) { return element % 2 == 0;});

copy_n(begin(a4), 3, begin(a2)); // copy 1st 3

copy(begin(a), position +1, position +1); // no overlap.. changing source

copy_backward(begin(v2), end(v2), end(a)); // copy from end of a

/*
moving: move(), move_backward() for moving elements from one to another collection
*/

/*
removing: remove(), remove_if()
*/
auto newend = remove(begin(a), end(a), 3); // remove val 3.. replaced w/ 0 shifted forward 
a.erase(newend, end(a));// delete elements from newend to end.. destructors
/*
transforming
*/
transform(begin(a), end(a), begin(a),
  [](int element){ return element * 2});
transform(begin(a),end(a)-1,begin(a)+1, begin(a), 
  [](int element1, int element2){ return element1 - element2 });

iota(begin(a), end(a), 1); // reset a's element's values 1..n

/*
uniquness
*/
sort(begin(a), end(a), [](int e1, int e2){return e1 > e2});
unique(begin(a),end(a))// removing consecutive duplicates
auto a8 = a;
a.erase(unique(begin(a), end(a)), end(a));

/*
reversing
*/
reverse(begin(a), end(a)); // collections, strings, etc
iter_swap(begin(a),end(a)-1); // swap 0th elem w/ size-1 elem
//reverse_copy
	return 0;
}
