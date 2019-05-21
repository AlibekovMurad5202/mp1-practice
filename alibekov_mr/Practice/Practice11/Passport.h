#ifndef __PASSPORT_H__
#define __PASSPORT_H__

#include "Date.h"
#include "Place.h"

class Passport
{
public:
  UINT series;
  UINT number;
  std::string byWhom;
  Date whenIssued;
  Date birthday;
  Place placeOfRegistration;

  Passport();
  ~Passport();
  Passport(const Passport& _p);

  const Passport& operator= (const Passport& _p);
  bool operator== (const Passport& _p) const;
};

#endif // !__PASSPORT_H__