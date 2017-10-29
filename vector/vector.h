#pragma once

#include <initializer_list>
#include <algorithm>

template <typename T>
class vector {
private:
  size_t sz;
  T* elem;
  size_t space;

public:

  // Constructors
  vector() : sz{0}, elem{nullptr}, space{0} {}
  explicit vector(size_t s);
  vector(std::initializer_list<T> lst);

  // Destructor
  ~vector() { delete[] elem; }

  // Copy constructor
  vector(const vector&);

  // Copy assignment
  vector& operator=(const vector&);

  // Move constructor
  vector(vector&&);

  // Move assignment
  vector& operator=(vector&&);

  T& operator[](int i) { return elem[i]; }
  const T& operator[](int i) const { return elem[i]; }

  size_t size() const { return sz; }
  size_t capacity() const {return space; }
  void reserve(size_t);
  void resize(size_t);
  void push_back(T);




};

#include "vector.inl"