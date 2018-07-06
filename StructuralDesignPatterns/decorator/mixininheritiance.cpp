#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <sstream>

using namespace std;

//class HtmlBuilder;

struct Namer
{
  string name;
  ostringstream str() const
  {
    ostringstream oss;
    oss << cout << name;
    return oss;
  }
};

template <typename T> struct mixin : T
{
  string name;
  //a(){}
  explicit mixin<T>(const string &name) : name{name}
  {
  }
  ostringstream str() const 
  {
     ostringstream oss;
     oss << T::str() << " is a name." << endl;
     return oss;
  }
};

int main()
{
  mixin<Namer> person { "Rob" };
  person.str();
 //getchar()
 return 0;
}
