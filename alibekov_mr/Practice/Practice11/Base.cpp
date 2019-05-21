#include "Base.h"

Base::Base()
{
  persons = nullptr;
  count = 0;
}

Base::~Base()
{
  for (int i = 0; i < count; i++)
    delete persons[i];
  delete[] persons;
}

Base::Base(const Base & _base)
{
  count = _base.count;
  persons = new Person*[count];
  for (int i = 0; i < count; i++)
  {
    persons[i] = new Person;
    *(persons[i]) = *(_base.persons[i]);
  }
}

Base::Base(int _count)
{
  count = _count;
  persons = new Person*[count];
  for (int i = 0; i < count; i++)
    persons[i] = new Person;
}

Person * Base::FindPerson(const Person & _person) const
{
  return nullptr;
}

const Base & Base::operator=(const Base & _base)
{
  if (this == &_base)
    return *this;
  
  for (int i = 0; i < count; i++)
    delete persons[i];
  delete[] persons;

  count = _base.count;
  persons = new Person*[count];
  for (int i = 0; i < count; i++)
  {
    persons[i] = new Person;
    *(persons[i]) = *(_base.persons[i]);
  }

  return *this;
}
