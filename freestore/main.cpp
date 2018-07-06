#include "Person.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::make_shared;

int main()
{
	/*{ //construct
		Resource local("local");
		string localString = local.Name();
	} //destruct
	// reserve new memory on freestore
	Resource* pRes = new Resource("created new");
	string newString = pRes->Name();
	int j=3;
	delete pRes; // manual memory management*/

	//smart pointers.. avoiding slicing (information gone when passing by value/copying to a derrived class
	shared_ptr<Resource> spPerson = make_shared<Person>("Robert Brown", 29);
	cout << "Shared res pointer: "+spPerson->Name() << endl;
	Person p("Rob",29);
	Resource* r = &p;
	cout << "Res pointer: "+r->Name() << endl;
	Person* pr = static_cast<Person*>(r); // cast to different pointer type
	cout << "Person pointer: "+pr->SmartName() << endl;
	
	return 0;
}
