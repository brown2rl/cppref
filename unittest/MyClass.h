#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class MyClass
{
private:
	int a;
	int b;
public:
	MyClass():a(0),b(1){}
	int function() { a=50*b*b; return a; }
	int flags() {
		cout << "Catch2 flags: \n -l - list tests \n --list-test-names-only\n -l [tag] - list test by a tag \n -t - list tags\n -h, -?, --help\n -f, --input file <filename>\n -o, --out <filename>\n -b, --break\n test name regex: name*, *name, *name*" << endl;
		return 0;
	}
};
