#include <iostream>
#include <string>
#include <vector>
#include <sstream> //string stream
#include <memory>

using namespace std;

class HtmlBuilder;

struct HtmlElement
{
  string name;
  string text;
  vector<HtmlElement> elements;
  string property;
  const size_t indent_size = 2;
  
  HtmlElement(){} //default constructor

  HtmlElement(const string& name, const string& text, const string& property): name{name}, text{text}, property{property}
  {
  }
  HtmlElement(const string& name, const string& property): name{name}, property{property}
  {
  }

  friend ostream& operator<<(ostream& os, HtmlElement& element)
  {
    int indent = 0;
    auto es = element.elements;
    string i(element.indent_size * indent, ' '); // repeat chars
    element.property.size() > 0 ? 
      os << i << "<" << element.name <<  ">" << endl :
      os << i << "<" << element.name << " " << element.property << ">" << endl;
    if (element.text.size() > 0)
      os << string(element.indent_size * (indent + 1), ' ') << element.text << endl;
    for (const auto& e : es) // inner tags in elements
      os << e.str(indent + 1);
    if(es.size() > 0 && element.text.size() > 0)
      os << i << "</" << element.name << ">" << endl;
    return os;
  }

  string str(int indent = 0) const
  {
    ostringstream oss;
    auto es = elements;
    string i(indent_size * indent, ' '); // repeat chars
    property == "" ? 
      oss << i << "<" << name <<  ">" << endl :
      oss << i << "<" << name << " " << property << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    for (const auto& e : elements) // inner tags in elements
      oss << e.str(indent + 1);
    if(es.size() > 0 || text.size() > 0)
      oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static HtmlBuilder build(string root_name, string root_property);

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

  HtmlBuilder& add_inline_child(string child_name, string child_property)
  {
    HtmlElement e{ child_name, child_property };
    root.elements.emplace_back(e);
    return *this;
  }

  HtmlBuilder& add_branch(HtmlElement e)
  {
    root.elements.emplace_back(e);
    return *this;
  }

  string str() const { return root.str(); }

  operator HtmlElement() { return root; }
};

HtmlBuilder HtmlElement::build(string root_name, string root_property)
{
  return HtmlBuilder{ root_name, root_property };
}

struct P : HtmlElement // <initializer_list>
{
};

struct img : HtmlElement
{
  //explicit img(const string& url) : HtmlElement("img"
};

int main()
{
 HtmlBuilder root{ "li", ""};
 HtmlBuilder branch{"p","class='picture'"};

 HtmlElement wtf = branch.add_inline_child("img","href='/img.png'").add_child("p","lorem epsom salt","class='paragraph'");

 HtmlElement child_branch = branch.add_inline_child("img","href='/img.png'").add_child("p","lorem epsom salt","class='paragraph'").add_branch(wtf);

 root.add_branch(child_branch).add_child("p","art?","class='cpp'");

 cout << root.str() << endl;
 return 0;
}
