/*
fluentbuilder.cpp

Authors: 
  Dimitri Nesteruk (dn@activemesa.com)
  Robert Brown (brown2rl@gmail.com)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream> //string stream
#include <memory>

using namespace std;

class HtmlBuilder; //forward declaration for build fn, with compiler constructor/destructor

struct HtmlElement
{
  string name;
  string text;
  string property="";
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement(){}

  HtmlElement(const string& name, const string& text, const string& property): name{name}, text{text}, property{property}
  {
  }

  string str(int indent = 0) const
  {
    ostringstream oss;
    string i(indent_size * indent, ' '); // repeat chars
    property == "" ? 
      oss << i << "<" << name <<  ">" << endl :
      oss << i << "<" << name << " " << property << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    for (const auto& e : elements) // inner tags in elements
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static HtmlBuilder build(string root_name, string root_property);
  static unique_ptr<HtmlBuilder> create(string root_name, string root_property);

};

struct HtmlBuilder
{

  HtmlElement root;
  
  HtmlBuilder(string root_name, string root_property) 
  {
    root.name = root_name;
    root.property = root_property;
  }

  HtmlBuilder& add_child(string child_name, string child_text, string child_property)
  {
    HtmlElement e{ child_name, child_text, child_property };
    root.elements.emplace_back(e);
    return *this;
  }

  HtmlBuilder* add_child2(string child_name, string child_text, string child_property)
  {
    HtmlElement e{ child_name, child_text, child_property };
    root.elements.emplace_back(e);
    return this;
  }

  string str() const { return root.str(); }

  operator HtmlElement() { return root; }
};

HtmlBuilder HtmlElement::build(string root_name, string root_property)
{
  return HtmlBuilder{ root_name, root_property };
}

unique_ptr<HtmlBuilder> HtmlElement::create(string root_name, string root_property)
{
  return make_unique<HtmlBuilder>(root_name, root_property);
}

int main()
{
 HtmlBuilder builder{ "ul","" };
 // fluent chaining
 builder.add_child("li","hello","")
              .add_child("li","world","");

  cout << "fluent chaining: " << endl;
  cout << builder.str() << endl;

 HtmlElement e = HtmlElement::build("ul","class='.col-md-3'").add_child("li", "hello","class='.cpp'").add_child("li","world","");

 cout << "operator= fluent chaining: " << endl;
 cout << e.str() << endl;

  HtmlElement ee = *HtmlElement::create("ul","class='.col-md-3, .smart-pointer")->add_child2("li", "hello","class='.cpp, .smart-pointer'")->add_child2("li","world","");

  cout << ee.str() << endl;
 return 0;
}
