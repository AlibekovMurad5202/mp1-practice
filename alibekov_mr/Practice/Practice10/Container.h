#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "iostream"
#include "MyExceptions.h"

template<typename T, int maxsize>
class Container
{
public:
  Container() : count(0), arr(new T[maxsize]) {};
  ~Container();
  Container(const Container<T, maxsize>& a): count(a.count), arr(new T[maxsize]) { for (int i = 0; i < count;) arr[i] = a.arr[i++]; }

  bool IsFull() const { return count == maxsize; }
  bool IsEmpty() const { return count == 0; }

  void Add(T a) { IsFull() ? throw ExceptionFullContainer(__LINE__, __FILE__) : arr[count++] = a; }
  int Find(const T& a) const;
  void Delete(T a) { IsEmpty() ? throw ExceptionEmptyContainer(__LINE__, __FILE__) : arr[Find(a)] = arr[--count]; }

  int getCount() { return count; }

  T& operator[] (int index);
  const T& operator[] (int index) const;

private:
  T* arr;
  int count;
};

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
  count = 0;
  delete[] arr;
}

template<typename T, int maxsize>
int Container<T, maxsize>::Find(const T& a) const
{
  for (int i = 0; i < count; i++)
    if (arr[i] == a)
      return i;
  return -1;
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int index)
{
  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
const T& Container<T, maxsize>::operator[](int index) const
{
  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

template<typename T, int maxsize>
class Container<T*, maxsize>
{
public:
  Container() : count(0), arr(new T* [maxsize]) {};
  ~Container();
  Container(const Container<T*, maxsize>& c);

  bool IsFull() const { return count == maxsize; }
  bool IsEmpty() const { return count == 0; }

  void Add(T* a);
  int Find(T* a) const;
  void Delete(T* a);

  int getCount() { return count; }

  T* operator[] (int index);
  T* const operator[] (int index) const;

private:
  T** arr;
  int count;
};

template<typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
  for (int i = 0; i < count; i++)
    delete arr[i];
  delete arr;
  count = 0;
}

template<typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)
  : count(a.count), arr(new T*[maxsize])
{ 
  for (int i = 0; i < count; i++)
  {
    arr[i] = new T;
    *arr[i] = *a.arr[i];
  }
}

template<typename T, int maxsize>
int Container<T*, maxsize>::Find(T* a) const
{
  for (int i = 0; i < count; i++)
    if (*arr[i] == *a)
      return i;
  throw -1;
}

template<typename T, int maxsize>
T* Container<T*, maxsize>::operator[](int index)
{
  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
T* const Container<T*, maxsize>::operator[](int index) const
{
  if ((index < 0) || (index >= count))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return arr[index];
}

template<typename T, int maxsize>
void Container<T*, maxsize>::Delete(T* a)
{
  if (IsEmpty())
    throw ExceptionEmptyContainer(__LINE__, __FILE__);

  *arr[Find(a)] = *arr[count - 1];
  delete arr[--count];
}

template<typename T, int maxsize>
void Container<T*, maxsize>::Add(T* a)
{
  if (IsFull())
    throw ExceptionFullContainer(__LINE__, __FILE__);
  arr[count] = new T;
  *arr[count++] = *a;
};

#endif // !__CONTAINER_H__
