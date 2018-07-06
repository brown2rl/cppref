#include <vector>
#include <string>
#include <iostream>

#include "Transaction.h"

class Account
{
private:
	double balance;
	std::vector<Transaction> log; // this would be saved somewhere
public:
	Account();
	//~Account(); //destructor
	void Report(char t, double amt) const;
	void AddToLog(double amt, std::string kind, double balance);
	bool Deposit(double amt);
	bool Withdraw(double amt);
	double Validate(double amt);
	void CashBack(double amt, Transaction& t);
	double BalanceValue();
};
