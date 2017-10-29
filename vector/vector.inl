template <typename T>
vector<T>::vector(size_t s)
  : sz{s}, elem{new T[s]}, space{s}
{
  for (int i = 0; i < sz; ++i) { elem[i] = {}; }
}

template <typename T>
vector<T>::vector(std::initializer_list<T> lst)
  : sz{lst.size()}, elem{new T[sz]}, space{sz}
{
  std::copy(lst.begin(), lst.end(), elem);
}


template <typename T>
vector<T>::vector(const vector<T>& v)
  : sz(v.sz), elem{new T[sz]}, space{sz}
{
  std::copy(v.elem, &v.elem[v.sz], elem);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& v)
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

template <typename T>
vector<T>::vector(vector&& v)
  : sz{v.sz}, elem{v.elem}, space{sz}
{
  v.sz = 0;
  v.elem = nullptr;
}

template <typename T>
vector<T>& vector<T>::operator=(vector&& v)
{
  delete[] elem;
  elem = v.elem;
  v.elem = nullptr;
  sz = v.sz;
  v.sz = 0;
  return *this;
}

template <typename T>
void vector<T>::reserve(size_t c)
{
  if (c < space) return;
  T* temp = new T[c];
  for (int i = 0; i < sz; ++i) { temp[i] = elem[i]; }
  delete[] elem;
  elem = temp;
  space = c;
}

template <typename T>
void vector<T>::resize(size_t s)
{
  reserve(s);
  for (int i = sz; i < s; ++i) { elem[i] = {}; }
  sz = s;
}

template <typename T>
void vector<T>::push_back(T element)
{
  if (!space) reserve(8);
  else if (sz == space) reserve(2*space);
  elem[sz] = element;
  ++sz;
}
