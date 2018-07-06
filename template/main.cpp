#include "Template.h"

int main()
{
	const auto a = 3;
	constexpr auto b = a*a; 
	multi_print(b,'a',2.2,'\n',5*5); 
	return 0;
}
