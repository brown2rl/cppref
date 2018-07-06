#include "Account.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::to_string;
using std::vector;

Account::Account(void):balance(0.0)// constructor init syntax
{
}

void Account::Report(char t, double amt) const
{
	if(t=='r'){
		for(int i = 0; i < log.size(); i++){
			cout << log[i].Report() << endl;
		}
	} else {
	vector<string> report;
	if(t=='d') { report.push_back("added $"+to_string(amt)); } else { report.push_back("removed $"+to_string(amt)); }
	report.push_back("balance: $"+to_string(balance));
	for(string item: report)
	{
		cout << item << endl;
	}
}
}

void Account::AddToLog(double amt, string kind, double balance)
{
	Transaction t(amt,kind,balance);
	log.push_back(t);
}
	

double Account::BalanceValue()
{
	double val = balance;
	return val;
}

void Account::CashBack(double a, Transaction& t) // passing an object by reference
{
	t.Bonus(a);
}

double Account::Validate(double amt)
{
	try {
		return amt/1.0;
	} catch (string e) {
		return 0.0;
	}
}

bool Account::Deposit(double amt)
{
	if (amt > 0.0)
	{
		balance += amt;
		Transaction t(amt,"Add",balance);
		log.push_back(t);
		if(amt > 1000.00)
			{
				double bonus = 5.00;
				CashBack(bonus,t);
				balance += bonus;
				cout << "Congrats!  A $"+to_string(bonus)+" bonus has been added to your deposit." << endl;
				log.push_back(t);
			}
		return true;
	}
	return false;
}

bool Account::Withdraw(double amt)
{
	if (amt > 0.0 && balance >= amt)
	{
		balance-=amt;
		AddToLog(amt,"Remove",balance);
		return true;
	}
	return false;
}
