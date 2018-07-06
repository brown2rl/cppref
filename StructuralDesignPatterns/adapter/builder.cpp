#include <iostream>
#include <string>
#include <vector>
#include <sstream> //string stream
#include <memory>

using namespace std;

//class HtmlBuilder;

struct HtmlElement
{
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement(){} //default constructor

  HtmlElement(const string& name, const string& text): name{name}, text{text} //init constructor
  {
  }

  string str(int indent = 0) const
  {
    ostringstream oss;
    string i(indent_size * indent, ' '); // repeat chars
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    for (const auto& e : elements) // inner tags in elements
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

};

struct HtmlBuilder
{

  HtmlElement root;
  
  HtmlBuilder(string root_name) 
  {
    root.name = root_name;
  }

  void add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    //return *this;
  }

  string str() const { return root.str(); }

  //operator HtmlElement() { return root; }  
};

/*HtmlBuilder HtmlElement::build(string root_name)
  {
    return HtmlBuilder{ root_name };
  }*/

int main()
{
 HtmlBuilder builder{ "ul" };
 builder.add_child("li","hello");

 //HtmlElement e = HtmlElement::build("ul").add_child("li", "hello");

 cout << builder.str() << endl;
 //getchar()
 return 0;
}
