#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;
//functional decorator
struct Logger
{
  function<void()> func;
  string name;

  Logger(const function<void()> &func, const string &name) : func{func}, name {name}
  {
  }

  void operator()() const
  {
    cout << "entering " << name << endl;
    func();
    cout << "exiting " << name << endl;
  }
};

template <typename Func> ()
{
  Func func;
  Logger2(Func func, const string &name) : func{func}, name {name}
  {
  }
    void operator()() const
  {
    cout << "entering " << name << endl;
    func();
    cout << "exiting " << name << endl;
  }
}

template <typename Func> auto make_log2(Func func, const string &name)
{
  return Logger2<Func>{func, name};
}

template <typename> struct Log3;

template <typename R, typename... Args> 
struct Log3(Func func, const string &name)
{
  function<R(Args...)> func;
  string name;
  return Logger2<Func>{func, name};

  Log3(const function<R(Args...)> &func, const string &name) : func{func}, name {name}
  {
  }

}

int main()
{
 Logger log{ [] (){ cout << "Hello world" << endl; }, "hello func" };

  log();
 return 0;
}
