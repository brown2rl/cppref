#include <string>
using std::string;
using std::to_string;


class Person
{
private:
	std::string name;
	int age;
public:
	Person(std::string name, int age): name(name), age(age){}
	//~Person();
	std::string Info() { return name+", "+to_string(age); }	
};
