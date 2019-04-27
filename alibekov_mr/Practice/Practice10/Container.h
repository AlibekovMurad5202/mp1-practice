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
  Container(const Container& c);

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
}

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
  count = 0;
  delete[] arr;
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

}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsFull() const
{
  return (count == maxsize) ? true : false;
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty() const
{
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
}

template<typename T, int maxsize>
int Container<T, maxsize>::Find(const T& a) const
{
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

#endif // !__CONTAINER_H__