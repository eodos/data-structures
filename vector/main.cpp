#include <iostream>

#include "vector.h"

template <typename T>
void print(vector<T> v);

int main(int argc, char const *argv[])
{
  // Default constructor
  vector<int> v1;
  print(v1);
  // Copy constructor
  vector<int> v2 = vector<int>(10);
  print(v2);
  // Constructor with list initializer
  vector<int> v3{1, 2, 3};
  print(v3);
  v3[0] = 5;
  print(v3);
  const vector<int> v4{1, 2, 3};
  print(v4);
  v3.reserve(10);
  print(v3);
  v3.resize(15);
  print(v3);
  v3.push_back(9);
  print(v3);

  return 0;
}

template <typename T>
void print(vector<T> v)
{
  std::cout << "Size: " << v.size() << std::endl;
  std::cout << "Capacity: " << v.capacity() << std::endl;
  for (int i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << ",";
  }
  std::cout << std::endl;
}