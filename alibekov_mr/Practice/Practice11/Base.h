#ifndef __BASE_H__
#define __BASE_H__

#include "Person.h"

class Base
{
public:
  Person *persons;

  Base();
  ~Base();
  Base(const Base& _base);
  explicit Base(Person* p);

  void Print() const;
  void PrintTheListOfPensioners() const;
  void Read(const std::string _fileName);
  void PrintInfoAboutPerson(Person& _person) const;
  Person* FindPerson(const Person& _person) const;

  const Base& operator= (const Base& _base);
};

#endif