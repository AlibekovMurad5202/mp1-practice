#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "iostream"
#include "MyExceptions.h"

template<typename T, int maxsize>
class Container
{
public:
  Container();
  ~Container();
  Container(const Container<T, maxsize>& c);

  bool IsFull() const;
  bool IsEmpty() const;

  void Add(T a);
  int Find(const T& a) const;
  void Delete(T a);

  int getCount() { return count; }

  T& operator[] (int index);
  const T& operator[] (int index) const;

private:
  T* arr;
  int count;
};

template<typename T, int maxsize>
Container<T, maxsize>::Container()
{
  count = 0;
  T* arr = nullptr;

  std::cout << "Container<T, maxsize>::Container()" << std::endl;
}

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
  count = 0;
  delete[] arr;

  std::cout << "Container<T, maxsize>::~Container()" << std::endl;
}

template<typename T, int maxsize>
Container<T, maxsize>::Container(const Container<T, maxsize>& a)
{
  count = a.count;
  if (count == 0)
    arr = nullptr;
  else
  {
    arr = new T[count];
    for (int i = 0; i < count; i++)
      arr[i] = a.arr[i];
  }

  std::cout << "Container<T, maxsize>::Container(const Container<T, maxsize>& a)" << std::endl;
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsFull() const
{
  std::cout << "bool Container<T, maxsize>::IsFull() const" << std::endl;

  return (count == maxsize) ? true : false;
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty() const
{
  std::cout << "bool Container<T, maxsize>::IsEmpty() const" << std::endl;

  return (count == 0) ? true : false;
}

template<typename T, int maxsize>
void Container<T, maxsize>::Add(T a)
{
  if (IsFull())
    throw ExceptionFullContainer(__LINE__, __FILE__);
   
  if (IsEmpty())
  {
    count++;
    delete[] arr;
    arr = new T[count];
    arr[0] = a;
    return;
  }

  T* tmp = new T[count];
  for (int i = 0; i < count; i++)
    tmp[i] = arr[i];

  delete[] arr;
  count++;
  arr = new T[count];
  for (int i = 0; i < count; i++)
    arr[i] = i == count - 1 ? a : tmp[i];
  delete[] tmp;

  std::cout << "void Container<T, maxsize>::Add(T a)" << std::endl;
}

template<typename T, int maxsize>
int Container<T, maxsize>::Find(const T& a) const
{
  std::cout << "int Container<T, maxsize>::Find(const T& a) const" << std::endl;

  for (int i = 0; i < count; i++)
    if (arr[i] == a)
      return i;
  throw ExceptionItemNotFound(__LINE__, __FILE__);
}

template<typename T, int maxsize>
void Container<T, maxsize>::Delete(T a) 
{
  if (IsEmpty())
    throw ExceptionEmptyContainer(__LINE__, __FILE__);
  int index = Find(a);

  if (count == 1)
  {
    count--;
    delete[] arr;
    arr = nullptr;
    return;
  }

  T* tmp = new T[count];
  for (int i = 0; i < count; i++)
    tmp[i] = arr[i];

  delete[] arr;
  count--;
  arr = new T[count];
  for (int i = 0; i < count; i++)
    arr[i] = tmp[i >= index ? i + 1 : i];
  delete[] tmp;

  std::cout << "void Container<T, maxsize>::Delete(T a)" << std::endl;
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int index)
{
  std::cout << "T& Container<T, maxsize>::operator[](int index)" << std::endl;

  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
const T& Container<T, maxsize>::operator[](int index) const
{
  std::cout << "const T& Container<T, maxsize>::operator[](int index) const" << std::endl;

  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
};




template<typename T, int maxsize>
class Container<T*, maxsize>
{
public:
  Container();
  ~Container();
  Container(const Container<T*, maxsize>& c);

  bool IsFull() const;
  bool IsEmpty() const;

  void Add(T* a);
  int Find(T* a) const;
  void Delete(T* a);

  int getCount() { return count; }

  T* operator[] (int index);
  const T* operator[] (int index) const;

private:
  T** arr;
  int count;
};

template<typename T, int maxsize>
Container<T*, maxsize>::Container()
{
  count = 0;
  T** arr = nullptr;

  std::cout << "Container<T*, maxsize>::Container()" << std::endl;
}

template<typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
  for (int i = 0; i < count; i++)
    delete arr[i];
  count = 0;
  delete arr;

  std::cout << "Container<T*, maxsize>::~Container()" << std::endl;
}

template<typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)
{
  count = a.count;
  if (count == 0)
    arr = nullptr;
  else
  {
    arr = new T*[count];
    for (int i = 0; i < count; i++)
    {
      arr[i] = new T;
      *arr[i] = *a.arr[i];
    }
  }

  std::cout << "Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)" << std::endl;
}

template<typename T, int maxsize>
bool Container<T*, maxsize>::IsFull() const
{
  std::cout << "bool Container<T*, maxsize>::IsFull() const" << std::endl;

  return (count == maxsize) ? true : false;
}

template<typename T, int maxsize>
bool Container<T*, maxsize>::IsEmpty() const
{
  std::cout << "bool Container<T*, maxsize>::IsEmpty() const" << std::endl;

  return (count == 0) ? true : false;
}

template<typename T, int maxsize>
int Container<T*, maxsize>::Find(T* a) const
{
  std::cout << "int Container<T*, maxsize>::Find(const T& a) const" << std::endl;

  for (int i = 0; i < count; i++)
    if (arr[i] == a)
      return i;
  throw ExceptionItemNotFound(__LINE__, __FILE__);
}

template<typename T, int maxsize>
T* Container<T*, maxsize>::operator[](int index)
{
  std::cout << "T* Container<T*, maxsize>::operator[](int index)" << std::endl;

  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
const T* Container<T*, maxsize>::operator[](int index) const
{
  std::cout << "const T* Container<T*, maxsize>::operator[](int index) const" << std::endl;

  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
void Container<T*, maxsize>::Delete(T* a)
{
  if (IsEmpty())
    throw ExceptionEmptyContainer(__LINE__, __FILE__);
  int index = Find(a);

  if (count == 1)
  {
    count--;
    delete arr[0];
    delete[] arr;
    arr = nullptr;
    return;
  }

  T** tmp = new T*[count];
  for (int i = 0; i < count; i++)
  {
    tmp[i] = new T;
    *tmp[i] = *arr[i];
  }
  for (int i = 0; i < count; i++)
    delete arr[i];
  delete[] arr;
  count--;
  arr = new T*[count];
  for (int i = 0; i < count; i++)
  {
    arr[i] = new T;
    *arr[i] = *tmp[i >= index ? i + 1 : i];
  }

  for (int i = 0; i < count + 1; i++)
    delete tmp[i];
  delete[] tmp;

  std::cout << "void Container<T*, maxsize>::Delete(T* a)" << std::endl;
}

template<typename T, int maxsize>
void Container<T*, maxsize>::Add(T* a)
{
  if (IsFull())
    throw ExceptionFullContainer(__LINE__, __FILE__);

  if (IsEmpty())
  {
    count++;
    delete[] arr;
    arr = new T*[count];
    arr[0] = new T;
    *arr[0] = *a;
    return;
  }

  T** tmp = new T*[count];
  for (int i = 0; i < count; i++)
  {
    tmp[i] = new T;
    *tmp[i] = *arr[i];
  }

  for (int i = 0; i < count; i++)
    delete arr[i];
  delete[] arr;
  count++;
  arr = new T*[count];
  for (int i = 0; i < count; i++)
  {
    arr[i] = new T;
    *arr[i] = i == count - 1 ? *a : *tmp[i];
  }

  for (int i = 0; i < count - 1; i++)
    delete tmp[i];
  delete[] tmp;

  std::cout << "void Container<T*, maxsize>::Add(T* a)" << std::endl;
};

#endif // !__CONTAINER_H__
