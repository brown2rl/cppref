class Human
{
private:
	char status;
//forward declarations (improve compilation)
	// types must be an integer type
	//hidden scope
	enum OrganSystem: unsigned short;
	OrganSystem _organ_system;
public:
	Human();
	//~Human()
};
