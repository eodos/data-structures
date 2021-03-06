template <typename T, typename A>
vector<T, A>::vector(size_t s)
  : sz{s}, elem{new T[s]}, space{s}
{
  for (int i = 0; i < sz; ++i) { elem[i] = {}; }
}

template <typename T, typename A>
vector<T, A>::vector(std::initializer_list<T> lst)
  : sz{lst.size()}, elem{new T[sz]}, space{sz}
{
  std::copy(lst.begin(), lst.end(), elem);
}


template <typename T, typename A>
vector<T, A>::vector(const vector<T, A>& v)
  : sz(v.sz), elem{new T[sz]}, space{sz}
{
  std::copy(v.elem, &v.elem[v.sz], elem);
}

template <typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector& v)
{
  if (this == &v) return *this; // Self-assignment

  if (v.sz <= space)
  {
    for (int i = 0; i < v.sz; ++i) { elem[i] = v[i]; }
    sz = v.sz;
    return *this;
  }

  delete[] elem;
  T* elem = new T[v.sz];
  std::copy(v.elem, &v.elem[v.sz], elem);
  sz = v.sz;
  return *this;
}

template <typename T, typename A>
vector<T, A>::vector(vector&& v)
  : sz{v.sz}, elem{v.elem}, space{sz}
{
  v.sz = 0;
  v.elem = nullptr;
}

template <typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& v)
{
  delete[] elem;
  elem = v.elem;
  v.elem = nullptr;
  sz = v.sz;
  v.sz = 0;
  return *this;
}

template <typename T, typename A>
T& vector<T, A>::at(int i)
{
  if (i < 0 || i >= sz) throw std::out_of_range("Index out of bounds");
  return elem[i];
}

template <typename T, typename A>
const T& vector<T, A>::at(int i) const
{
  if (i < 0 || i >= sz) throw std::out_of_range("Index out of bounds");
  return elem[i];
}

template <typename T, typename A>
void vector<T, A>::reserve(size_t c)
{
  if (c < space) return;
  std::unique_ptr<T*> temp = std::make_unique<T*>(alloc.allocate(c));
  for (int i = 0; i < sz; ++i) { alloc.construct(&(*temp)[i], elem[i]); }
  for (int i = 0; i < sz; ++i) { alloc.destroy(&elem[i]); }
  alloc.deallocate(elem, space);
  elem = *temp.release();
  space = c;
}

template <typename T, typename A>
void vector<T, A>::resize(size_t s, T val)
{
  reserve(s);
  for (int i = sz; i < s; ++i) { alloc.construct(&elem[i], val); }
  sz = s;
}

template <typename T, typename A>
void vector<T, A>::push_back(T val)
{
  if (!space) reserve(8);
  else if (sz == space) reserve(2*space);
  alloc.construct(&elem[sz], val);
  ++sz;
}

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::insert(iterator p, const T& val)
{
  size_t i = p - this->begin();
  if (sz == space) reserve(sz == 0 ? 8 : 2*sz);
  // Copy last element into uninitialized space
  alloc.construct(elem + sz, *(this->end() - 1));
  ++sz;
  iterator pp = this->begin() + i;
  for (auto ii = this->end() - 1; ii != pp; --ii)
  {
    *(ii) = *(ii - 1);
  }
  // Insert new element
  *(this->begin() + i) = val;
  return pp;
}

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::erase(iterator p)
{
  if (p == this->end()) return p;
  for (auto i = p; i != this->end(); ++i)
  {
    *(i) = *(i + 1);
  }
  alloc.destroy(&*(this->end() - 1));
  --sz;
  return p;
}
