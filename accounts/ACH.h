#include <string>

template <class T> //T = type placeholder
class ACH
{
private:
	T confirmation;
public:
	ACH(T type): confirmation(type){};
	T Execute(T const& account1, T const& account2, T const& amt){
		return confirmation+= account1+account2+amt;
	};
};
	
