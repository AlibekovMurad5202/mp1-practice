#ifndef __PERSON_H__
#define __PERSON_H__

#include "Date.h"
#include "Passport.h"
#include "Education.h"

const std::string unknown = "UNKNOWN";

class Person
{
public:
  Passport passport;
  Education education;
  std::string specialty;
  std::string subdivision;
  std::string position;
  UINT salary;
  Date dateOfEntryIntoTheCompany;
  Date lastAppointmentDate;

  Person();
  ~Person();
  Person(const Person& _person);

  void Print() const;
  bool isPensioner() const;

  const Person& operator= (const Person& _person);
  bool operator== (const Person& _person) const;
};

#endif