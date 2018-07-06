#include <iostream>
#include "Brokerage.h"

using namespace std;

int main()
{
	Account a1;
	// deposit
	cout << "Welcome to Accounts!" << endl;
	char leave = 'n';
	while (leave == 'n')
	{
		Checking automated;
		automated.Teller(a1);
		
		Brokerage dealer;
		dealer.Broker(a1);

		cout << "Before you leave, would you like a statement? (y/n)" << endl;
		char wantlog = 'y';
		cin >> wantlog;
		if (wantlog == 'n') 
		{
			leave = 'y';
		} else if (wantlog == 'y')
			{
			a1.Report('r',0.0);
			leave = 'y';
			}
	}
	return 0;
}
