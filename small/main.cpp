#include <iostream>
#include <string>
#include <vector>

#include "Functions.h"

using namespace std; // limited usage (ensure no function/object naming clashes)

int main()
{
	int a = 2; // signed
	float b = 5.2;
	bool answer = true;
	vector<string> v;
	while (answer) {
		/*cout << "Fibonnaci: " << endl;
		cin >> a;
		fib(a);
		cout << "Hello!" << endl << a+b << endl << b/a << endl << a*b << endl << a-b << endl;*/
		cout << "word to philosophy: " << endl;
		string aa = "";
		cin >> aa;
		string aaa = "a ";
		if (aa[0] == 'a'){ aaa = "an";}
		string bb = "member is "+aaa;
		if (manip(aa).length() % 2 == 0) { bb = "philosophy is ";}
		cout << "your new "+bb+manip(aa) << endl;
		v = fill_vec(1,manip(aa), v);
		cout << "Keep going? (y/n)" << endl;
		char ans ='y';
		cin >> ans;
		if (ans == 'n'){ answer = false; }
	}
	disp_vec(v, 'i');
	cout << endl;
	return 0;
}
