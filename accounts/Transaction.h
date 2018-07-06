#include <string>

class Transaction
{
private:
	double amt;
	std::string kind;
	double balance;
public:
	Transaction(double amt, std::string kind, double balance);
	//~Transaction(double amt, std::string kind, double balance);
	std::string Report() const;
	void Bonus(double amt);
};
