#include "Account.h"

#include <vector>
#include <string>
#include <iostream>

class Brokerage : 	
	public Account
{
	private:
		std::vector<std::string> vehicles;
		std::string username;
		int securitiescount;
		double holdings;
		double returns;
		double balance;
	public:
		Brokerage();
	  //~Brokerage();
		void AddVehicle(std::string vehicle);
		bool SecuritiesCheck(Account& a1);
		double Buy(int qty, Account& a1);
		double Sell(int qty, Account& a1);
		void Broker(Account& a1);
};

class Checking :
	public Account
{
public:
	Checking();
	//~Checking(); //destructor
	void Teller(Account& a1);
};
