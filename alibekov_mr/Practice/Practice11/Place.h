#ifndef __PLACE_H__
#define __PLACE_H__

#include "string"
#include "iostream"
#include "MyExceptions.h"

#define UINT unsigned int

const std::string unknown = "UNKNOWN";

class Place
{
public:
  std::string region;
  std::string registrationPoint;
  std::string district;
  std::string street;
  UINT flat;
  UINT house;

  Place();
  ~Place();
  Place(const Place& _place);

  const Place& operator= (const Place& _place);
  bool operator== (const Place& _place) const;
};

#endif // !__PLACE_H__
