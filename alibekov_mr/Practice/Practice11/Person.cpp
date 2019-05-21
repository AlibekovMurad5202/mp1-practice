#include "Person.h"

Person::Person()
{
  salary = 0;
  specialty = unknown;
  subdivision = unknown;
  position = unknown;
}

Person::~Person()
{
}

Person::Person(const Person & _person)
{
  passport = _person.passport;
  education = _person.education;
  specialty = _person.specialty;
  subdivision = _person.subdivision;
  position = _person.position;
  salary = _person.salary;
  dateOfEntryIntoTheCompany = _person.dateOfEntryIntoTheCompany;
  lastAppointmentDate = _person.lastAppointmentDate;
}

const Person & Person::operator=(const Person & _person)
{
  if (this == &_person)
    return *this;
  passport = _person.passport;
  education = _person.education;
  specialty = _person.specialty;
  subdivision = _person.subdivision;
  position = _person.position;
  salary = _person.salary;
  dateOfEntryIntoTheCompany = _person.dateOfEntryIntoTheCompany;
  lastAppointmentDate = _person.lastAppointmentDate;
  return *this;
}

bool Person::operator==(const Person & _person) const
{
  return (passport == _person.passport)
      && (education == _person.education)
      && (specialty == _person.specialty)
      && (subdivision == _person.subdivision)
      && (position == _person.position)
      && (salary == _person.salary)
      && (dateOfEntryIntoTheCompany == _person.dateOfEntryIntoTheCompany)
      && (lastAppointmentDate == _person.lastAppointmentDate);
}
