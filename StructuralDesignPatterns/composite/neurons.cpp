#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

struct Neuron
{
  vector<Neuron*> in, out;
  long id;

  Neuron()
  {
    static long id = 0;
    this->id = id++;
  }

  void connect(Neuron &n)
  {
    out.push_back(&n);
    n.in.push_back(this);
  }

  Neuron* begin() { return this; }
  Neuron* end() { return this + 1; }

  template <typename T> void connect(T& n)
  {
     for (Neuron& to : n)
       connect(to);
  }

  friend ostream& operator<<(ostream& os, const Neuron& ns)
  {
    for (Neuron* n : ns.in)
      os << n->id << "\t--->\t" << ns.id <<  endl;

    for (Neuron* n : ns.out)
      os << n->id << "\t<---\t" << ns.id << endl;

    return os;
  }
 };

struct NeuronLayer : vector<Neuron>
{
  explicit NeuronLayer(long count)
  {
    while (count --> 0)
      emplace_back(Neuron{});
  }

  template <typename T> void connect(T& n)
  {
    for (Neuron& from : *this)
      for (Neuron& to : n)
        from.connect(to);
  }

  friend ostream& operator<<(ostream& os, const NeuronLayer& nl)
  {
    for (auto& n : nl) // for neuron in neuron lyer
      os << n;
    
    return os;
  }
};

int main()
{
  Neuron n1, n2;
  n1.connect(n2);

  cout << n1 << n2 << endl;

  NeuronLayer l1 { 500000000000000 };
  Neuron n3;
  l1.connect(n3);   

  cout << "Neuron " << n3.id << endl << n3 << endl;
  cout << "Layer 1" << endl << l1 << endl;

  NeuronLayer l2 { 20000000000000000 }, l3 { 300000000000000};
  l2.connect(l3);

  cout << "Layer 2" << endl << l2 << endl;
  cout << "Layer 3" << endl << l3 << endl;

 return 0;
}
