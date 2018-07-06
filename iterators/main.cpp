#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	//back_inserter.. vector
vector<int> a;
fill_n(back_inserter(a), 6, 2); // insert 6 2's
generate_n(back_inserter(a), 10, 
  [n=0]()mutable{return n++}); // insert 10 increasing value elements.. allowing n to be mutable
transform(begin(a),end(a),back_inserter(a), 
  [](int element1, int element2){ return element1 - element2 });
vector<int> a2;
copy_if(begin(a), end(a), back_inserter(a2), // copy elements w/ even values
  [](int element) { return element % 2 == 0;});
 
 //front_inserter.. deque
deque<int> b;
fill_n(front_inserter(b), 6, 2);
generate_n(front_inserter(a), 10, 
  [n=0]()mutable{return n++}); 

// rend - point to -1 element
// end - point to N+1 element
// rbegin - point to Nth element
// begin - point to 0th element
// cbegin - const iterator
// iterator operators - +=, -+, ++, --
	return 0;
}
