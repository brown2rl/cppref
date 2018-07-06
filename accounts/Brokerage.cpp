#include "Brokerage.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
// initializing Account for inheritence
Brokerage::Brokerage(): Account(),securitiescount(0),holdings(0.0),returns(0.0)
{
}

void Brokerage::AddVehicle(string vehicle)
{
	vehicles.push_back(vehicle);
	cout << "Activated the "+vehicle+" vehicle on your account." << endl;
}

bool Brokerage::SecuritiesCheck(Account& a1)
{
	balance = a1.BalanceValue();
	if(securitiescount == 0 && balance >= 10.0){
		int number = 0;
		while(securitiescount == 0)
		{		
			cout << "Let's buy your first security. How many? (they are all $10)" << endl;
			cin >> number;
			if(balance >= number*10.0)
			{
				balance -= number*10.0;
				a1.Withdraw(number*10.0);
				securitiescount += number;
				holdings = securitiescount*10.0;
				cout << username+" now holds $"+to_string(holdings) << endl;
				a1.AddToLog(number*10.0,"BUY",balance);
				return true;
			} else {
				cout << "Purchase exceeds your balance of $"+to_string(balance)+". Let's try again." << endl;
				cin >> number;
			}
		}
	}
	return false;
}

double Brokerage::Buy(int qty, Account& a1)
{
	if(balance >= qty*10.0){
		balance -= qty*10.0;		
		a1.Withdraw(qty*10.0);
		securitiescount += qty;		
		holdings = securitiescount*10.0;
		cout << username+" now holds $ "+to_string(holdings) << endl;
		a1.Report('w',0.0);
		a1.AddToLog(qty*10.0,"BUY",a1.BalanceValue());		
		return balance;				
	} else {
					cout << "Purchase exceeds your balance of $"+to_string(balance)+". Let's try again." << endl;
					int number = 0;
					cin >> number;
					Buy(number, a1);
	}
}

double Brokerage::Sell(int qty, Account& a1)
{
	if(securitiescount >= qty)
		{
			balance += qty*11.0;			
			securitiescount -= qty;
			a1.AddToLog(qty*10.0,"SELL",balance);
			
			holdings = securitiescount*10.0;
			double profit = qty*11.0 - qty*10.0;
			a1.Deposit(qty*11.0);
			cout << "Congrats.  "+username+" account earned $"+to_string(profit)+"!" << endl;
			return balance;
		} else {
			cout << "Selling quantity exceeds available securities of "+to_string(securitiescount)+". Let's try again." << endl;
			int number = 0;
			cin >> number;
			Sell(number, a1);
		}
}

void Brokerage::Broker(Account& a1)
{
	cout << "Would you like to convert this to an investment account?" << endl;
	char gains = 'y';
	cin >> gains;

	if (gains=='y')
		{
			cout << "Ok, what's your account named?" << endl;
			string name;
			cin >> name;
			username = name;
			cout << "Activating financial vehicles for "+name+"..." << endl;
			AddVehicle("stocks");
			AddVehicle("options");
			AddVehicle("mutuals");
			AddVehicle("forex");
			AddVehicle("sweeps");
			SecuritiesCheck(a1);
			char trade = 'y';
			while(trade == 'y')
			{
				char action = 's';
				int qty = 0;
				cout << "Buy or Sell? (b/s)" << endl;
				cin >> action;
				if(action == 's')
				{
					cout << "How much? (you have "+to_string(securitiescount)+")." << endl;					
					cin >> qty;					
					Sell(qty, a1);
				} else if (action=='b'){
					cout << "How much? (you have "+to_string(securitiescount)+")." << endl;
					cin >> qty;
					Buy(qty, a1);
				}
				cout << "Keep trading? (y/n)" << endl;
				cin >> trade;
			}
		}
}

Checking::Checking(): Account()
{
}

void Checking::Teller(Account& a1)
{

	char another = 'y';
	while (another == 'y')
	{
		cout << "Add or Receive money (a/r)?" << endl;
		char aa = 'a';
		cin >> aa;
		if(aa == 'r') 
		{
			cout << "Ok, how much?" << endl;
			auto amt=0.0;
			cin >> amt;
			if(a1.Withdraw(amt/1.0))
			{
				a1.Report('w',amt);
			} 
		} else if (aa == 'a')
			{
				cout << "Ok, how much?" << endl;
				auto amt=0.0;
				cin >> amt;
				if(a1.Deposit(amt/1.0))
				{
					a1.Report('d',amt);
				}					
			}
			cout << "Would you like to make another entry? (y/n)" << endl;
			cin >> another;
	}
}
