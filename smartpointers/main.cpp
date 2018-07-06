#include <iostream>
#include <memory>
#include <string>

using namespace std;
using std::to_string;
using std::string;
using std::cout;
using std::endl; 

struct Account
{
	unsigned id;
	float balance;

	Account(unsigned id_, float balance_):
		id { id_ },
		balance{ balance_ }
		{}
	~Account(){}
};

auto ObtainAccount() -> unique_ptr<Account>
{
	return make_unique<Account>(1,0.0);
}

auto UpdateAccount(unique_ptr<Account> acct) -> unique_ptr<Account>
{
	acct->balance += 1000.00f;
	return acct;
}

void Contribution(shared_ptr<Account> acct, float amt)
{
	acct->balance += amt;
	cout << "mutual balance: "+to_string(acct->balance) << endl;
	cout << "contributors: "+to_string(acct.use_count()-1) << endl;
	//return acct;
}

int main()
{
	auto checking = make_unique<Account>(3, 100.0);
	//auto brokerage = move(checking);
	auto update = UpdateAccount(move(checking));
  cout << "updated balance: "+to_string(update->balance) << endl;
	auto account = ObtainAccount();
	auto id = to_string(account->id);
	cout << id << endl;
	auto member = make_shared<Account>(5,1000.0);
	auto member1 = member;
	Contribution(member1, 1000.0f);	
	auto member2 = member;
	Contribution(member2, 1000.0f);
	
	return 0;
}
