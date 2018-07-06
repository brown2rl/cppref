#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sorting, count
//#include <wstring> // unicode

using namespace std;

void fib(int start)
{
	int res = (start-1)+(start-2);
	if(res < 5000) {
		cout << res << endl;
		fib(res);
	}
}

string manip(string a)
{
	string b = "ism";
	if (a.length() % 2 == 0){ b = "ist"; }
	return a += b;
}

vector<string> fill_vec(int a, string b, vector<string> v) // extrapolate item types
{
	for (int i=0; i<a; i++)
	{
		v.push_back(b);
	}
	return v;
}

void disp_vec(vector<string> v, char t)
{
	if(t=='r')
	{
		cout << "your new philosphies and members: " << endl;
		for(string item: v) // ranged for loop
		{
			cout << item << ", ";
		}
		cout << endl;
	} else if (t=='t')
		{
			cout << "your new philosphies and members: " << endl;
			for(unsigned int i = 0; i < v.size(); i++) //unsigned b/c size() returns >0
			{
				cout << v[i] << " ";  
			}
		} else if (t == 'i')
			{
				cout << "your new philosphies and members: " << endl;
				for(auto i = begin(v); i != end(v); i++) // iterator functions in vector template
					{
						cout << *i << " "; // *i of iterator points to value in v
					}
			}
}

vector<string> sort_vec(vector<string> v)
{
	sort(begin(v), end(v)); // alphabetical / numerical orders
	return v;
}

int count_chars_vec(vector<string> v, char c)
{
	int a = count(begin(v[0]), end(v[0]), c);
	return a;
}

int add(int a, int b, int c)
{
	return a+b+c;
}

string add(string a, string b)
{
	return a+b;
}
