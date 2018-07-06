#include <iostream>
#include <string>

using namespace std;

// pimpl (pointer to implementation) idiom

// Person.h interface
struct Person
{
  string name;

  struct PersonImpl;  // implementation
  PersonImpl *impl;

  Person();
  ~Person();

  void greet();
};

// Person.cpp
struct Person::PersonImpl
{
  void greet(Person *p); // mirrored from person
};

void Person::PersonImpl::greet(Person *p)
{
  cout << "hi, i'm " << p->name << endl;
}

Person::Person() : impl(new PersonImpl)
{
}

Person::~Person()
{
  delete impl;
}

void Person::greet()
{
  impl->greet(this);
}

// main.cpp
int main()
{
  Person p;
  p.name = "Rob";
  p.greet();
  
 return 0;
}
