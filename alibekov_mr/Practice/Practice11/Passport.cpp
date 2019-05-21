#include "Passport.h"

Passport::Passport()
{
  series = 0;
  number = 0;
  byWhom = "UNKNOWN";
}

Passport::~Passport()
{
}

Passport::Passport(const Passport & _p)
{
  series = _p.series;
  number = _p.number;
  byWhom = _p.byWhom;
  whenIssued = _p.whenIssued;
  birthday = _p.birthday;
  placeOfRegistration = _p.placeOfRegistration;
}

const Passport & Passport::operator=(const Passport & _p)
{
  if (this == &_p)
    return *this;
  series = _p.series;
  number = _p.number;
  byWhom = _p.byWhom;
  whenIssued = _p.whenIssued;
  birthday = _p.birthday;
  placeOfRegistration = _p.placeOfRegistration;
  return *this;
}

bool Passport::operator==(const Passport & _p) const
{
  return (series == _p.series)
      && (number == _p.number)
      && (byWhom == _p.byWhom)
      && (whenIssued == _p.whenIssued)
      && (birthday == _p.birthday)
      && (placeOfRegistration == _p.placeOfRegistration);
}
