#include "Transaction.h"
#include "Status.h"
//#include "ACH.h"

using std::string;
using std::to_string;

Transaction::Transaction(double a, string k, double b):amt(a),kind(k),balance(b)
{
/*
this -> amt = amt;
this -> kind = kind;
this -> balance = balance;
*/
}
/*
ACH<Transaction> transfer(kind);
transfer.execute(account1, account2, amt);
*/

//using enums
//TransactionStatus s = TransactionStatus::posted;

string Transaction::Report() const
{
	string report = kind + " $" + to_string(amt)+", $"+to_string(balance)+" available";
	return report;
}

void Transaction::Bonus(double a)
{
	amt = a;
	kind = "Bonus";
	balance += a;
}
