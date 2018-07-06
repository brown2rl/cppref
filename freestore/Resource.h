#include <string>

class Resource
{
private:
	std::string name;
public:
	Resource(std::string n);
	~Resource(void);
	virtual std::string Name() const {return name;} //overridable for pointer to inherited class
};
