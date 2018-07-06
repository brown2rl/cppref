#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::multimap;
using std::pair;
#include "Person.h"

int main()
{
	multimap<string, char> m;
	Person a("Rob",29);
	Person b("Joe",30);
	Person c("Mark",28);

	pair<string,char> ap(a.Info(), 'm');
	m.insert(ap); //iterator pointing to new element
	pair<string,char> bp(b.Info(), 'm');
	m.insert(bp);
	pair<string,char> cp(c.Info(), 'm');
	m.insert(cp);

	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << i->second << endl;
	}
	//auto range = m.equal_range(1);
	
	//auto q = m.find();
	//cout << "Found: "+q->first.Info()+" "+q->second << endl;

	//auto qq = m[];
	//cout << qq << endl;
//reverse access
	//for (auto i = m.rbegin(); i != m.rend(); i++)
	//{
		//cout << i->first << endl;
		//cout << i->second << endl;
	//}

	return 0;
}
