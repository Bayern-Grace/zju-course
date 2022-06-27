#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
  Vector<int> x; //default ctor
  cout << "----ctor----" << endl << "x.size: " << x.size() << ", x.empty: "; //check whether it is empty
  if (!x.empty())
    cout << "True" << endl; 
  else
    cout << "False" << endl;
  for (int i = 0; i < 10; i++)
    x.push_back(i); //push elements into Vector x
  cout << "----push_back----" << endl << "x: ";
  for (int i = 0; i < 10; i++)
    cout << x[i] << " "; //use index to access elements without checking index
  cout << endl;
  cout << "x.size: " << x.size() << ", x.empty: ";
  if (!x.empty())
    cout << "True" << endl; 
  else
    cout << "False" << endl;
  Vector<int> y(5); //create a vector for holding 'size' elements
  cout << "----ctor with a size----" << endl << "y.size: " << y.size() << ", y.empty: ";
  if (!y.empty())
    cout << "True" << endl; 
  else
    cout << "False" << endl;
  for (int i = 0; i < 5; i++)
    y.push_back(-i);
  cout << "----push_back----" << endl << "y: ";
  for (int i = 0; i < 5; i++)
    cout << y[i] << " ";
  cout << endl;
  Vector<int> z = y; //copy ctor
  cout << "----copy ctor----" << endl << "z: ";
  for (int i = 0; i < 5; i++)
    cout << z[i] << " ";
  cout << endl;
  z.clear(); //clear the contents
  cout << "----clear----" << endl << "z.size: " << z.size() << ", z.empty: ";
  if (!z.empty())
    cout << "True" << endl; 
  else
    cout << "False" << endl;
  cout << "----normal access----" << endl << "x[4]: " << x.at(4) << endl; // accesses the specified element
  cout << "----access x[100]----" << endl;  // throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
  x.at(100);
}