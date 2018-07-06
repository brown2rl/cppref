#include "Person.h"

using std::string;
using std::to_string;
using std::move;

/*
rule of 5:
1. move constructor - moving to another object
2. move assignment operator - delete then move to another object
3. copy constructor - use new to init from existing value
4. copy assignment operator - delete then use new to initialize
5. destructor - deletes from new
*/

Person::Person(string name, int number): Resource(name), number(number), pRes(nullptr) {}

Person::~Person() //5
{
	delete pRes;
}

string Person::Name() const //override base function
{
	return Resource::Name()+" "+to_string(number);//pRes? pRes->Name() : "";
}

string Person::SmartName() const
{
	return Resource::Name()+to_string(number);
}

void Person::SetName(string name)
{
	delete pRes;
	pRes=new Resource("Resource for "+Resource::Name());
}
// deep copy constructor.. making/init a new addressable object
Person::Person(Person const& p): Resource(p.pRes->Name()) //3
{
	pRes = new Resource(p.pRes->Name());
}
// deep copy assignment.. 
Person& Person::operator=(const Person& p) //4
{
	//self assignment check
	if(this == &p)
	{
		return *this;
	}
		// delete object's pointer to old superclass object
	delete pRes;
		// assign current pointer to new superclass object
	pRes=new Resource(p.pRes->Name());
		// return pointer to current instance of subclass object
	return *this;
}
// move auto resolves rvalues and lvalues
// shallow copy..  move 
Person:: Person(Person&& p): Resource(p.pRes->Name()),number(move(p.number)), pRes(move(p.pRes)) //move constructor
{
	delete p.pRes;
}
Person& Person::operator=(Person&& p)//move assignment operator
{
	if(this==&p)
	{
		return *this;
	}
	delete pRes;
	pRes=move(p.pRes);
	number=move(p.number);
	return *this;
}
