#include <string>
using std::string;
using std::to_string;
#include <exception>
using std::exception;
using std::invalid_argument;

class Poly
{
private:
	std::string name;
	int sides;
public:
	Poly(std::string name, int sides): name(name), sides(sides){
		if(sides<3) {
			throw invalid_argument("Error: "+name+" sides must be greater than 3.");
		}
	}
	//~Person();
	std::string Info() { return name+" has "+to_string(sides) + " sides."; }	
};
