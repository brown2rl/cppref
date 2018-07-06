#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

struct Expression
{
  virtual double eval() =0;
  virtual void collect(vector<double> &v) = 0; //visitor pattern
};

struct Literal : Expression
{
  double val;
  explicit Literal(const double val) : val{val}
  {
  }
  double eval() override
  {
     return val;
  }
  void collect(vector<double> &v) override
  {
    v.push_back(val);
  }
};

struct Add : Expression
{
  shared_ptr<Expression> left, right;

  Add(const shared_ptr<Expression> &left, const shared_ptr<Expression> &right) : left{left}, right{right}
  {
  };

  double eval() override
  {
    return left->eval() + right->eval();
  }

  void collect(vector<double> &v) override
  {
    left->collect(v);
    right->collect(v);
  }
};

int main()
{
  Add sum { make_shared<Literal>(2), make_shared<Add>(make_shared<Literal>(3), make_shared<Literal>(5)) };

 cout << "2+(3+5) = " << sum.eval() << endl;

  vector<double> v;
  sum.collect(v);
  for (auto x : v)
    cout << x << "\t";
    cout << endl;

  vector<double> vals { 2,3,5};
  double s = 0;
  for (auto x : vals) s += x;
  cout << "average: " << (s / vals.size()) << endl;

   

 return 0;
}
