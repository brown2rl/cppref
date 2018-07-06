#include "Resource.h"
#include <string>
//#include <memory> //smart pointers
/*
unique_ptr - noncopyable, movable (use std::move)
shared_ptr - copyable, reference counted
*/

class Person: public Resource
{
private:
	int number;
	Resource* pRes; //can rewrite as smart pointer
public:
	Person(std::string name, int number);	
//noexcept to override compiler automation copies and moves
//deep copies
	Person(Person const& P) noexcept; //copy constructor
	Person& operator=(const Person& p);//copy assignment operator
//shallow copies
	Person(Person&&) noexcept;//move constructor
	Person& operator=(Person&&);//move assignment operator
	//Person& operator+(const Person& p) &; //lvalue operator overload
	//Person& operator+(Person& p) &&; //rvalue (if const, both must be const)
	~Person(); //destructor
	std::string Name() const;
	std::string SmartName() const;
	int Number() const {return number;}
	void SetNumber(int number) {
		number = number;
	}
	void SetName(std::string name);
	void AddRes();
};
