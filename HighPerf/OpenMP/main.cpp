#include <vector>
#include <iostream>

using namespace std;

void hellow_orld()
{
  //omp_set_num_threads(8); // setting 8 threads

#pragma omp parallel // run below in parallel
#pragma omp critical // make critical sections for coherency in one output.. not split by threads
  //cout << "Hello, OpenMP " << omp_get_thread_num() << " / " << omp_get_num_threads() << endl;
  cout << "Hello, Open MP" << endl;
}

void pfor()
{
#pragma omp parallel for
  for(int i = 0; i < 5; i++) { cout << "p for" << endl; } 
}

void sections()
{
#pragma omp parallel sections
{
#pragma omp section
{
  //section A task
}
#pragma omp section
{
 //section B task
}
}
}

void single_main()
{
#pragma omp parallel
{
#pragma omp single
{
 // capture user input on single thread
}

 // barrier between processing input and output
#pragma omp barrier

#pragma omp master
{
 // print user input on main thread
}
}
}

void sync()
{
  printf("\nATOMIC\n");
  int sum = 0;
// use 100 threads
#pragma omp parallel for num_threads(100)
  for (int i = 0; i < 100; i++)
  {
#pragma omp atomic // makes sum atomic
    ++sum;
  }
  cout << sum; // 100
  printf("\nORDERED\n");
  vector<int> num { 1,2,3,4,5 };
  vector<int> num2 { 0,0,0,0,0 };
#pragma omp parallel for ordered
 // iterate thread-safe collection
  for(int i = 0; i < 5; i++) { num[i] = i; } 

#pragma omp ordered
 // write thread-safe collection
  for(int i =0; i < 5; i++) { cout << num[i] << endl; }
}

void data()
{
  int i = 10;
#pragma omp parallel for private(i) // thread-local versions uninit of i
  //some for loop using i
#pragma omp parallel for firstprivate(i) // thread-local versions of i = 10
  // some for loop using i
#pragma omp parallel for lastprivate(i) // thread-local versions of i = last result from for loop
  // some for loop using i
  for(int i = 0; i < 9; i++) { cout << i << endl; } 
}

int main()
{

 return 0;
}
