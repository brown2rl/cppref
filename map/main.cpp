#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::map;
using std::pair;
#include "Person.h"

int main()
{
	map<string, char> m;
	Person a("Rob",29);
	Person b("Joe",30);
	Person c("Mark",28);

	pair<string,char> ap(a.Info(), 'm');
	m.insert(ap);
	pair<string,char> bp(b.Info(), 'm');
	m.insert(bp);
	pair<string,char> cp(c.Info(), 'm');
	//auto [pos, success] = m.insert(cp); // structured bindings
	//success ? cout << "Inserted Mark"  : cout << "Mark skipped";

	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << i->second << endl;
	}
// structured bindings
  //for (const auto& [name, age] : m) {
    //cout << name << ' ' << age << '\n';
 // }
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

