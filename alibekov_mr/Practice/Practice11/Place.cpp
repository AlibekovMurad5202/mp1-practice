#include "Place.h"

Place::Place()
{
  region = unknown;
  registrationPoint = unknown;
  district = unknown;
  street = unknown;
  flat = 0;
  house = 0;
}

Place::~Place()
{
}

Place::Place(const Place & _place)
{
  region = _place.region;
  registrationPoint = _place.registrationPoint;
  district = _place.district;
  street = _place.street;
  flat = _place.flat;
  house = _place.house;
}

const Place & Place::operator=(const Place & _place)
{
  if (this == &_place)
    return *this;
  region = _place.region;
  registrationPoint = _place.registrationPoint;
  district = _place.district;
  street = _place.street;
  flat = _place.flat;
  house = _place.house;
  return *this;
}

bool Place::operator==(const Place & _place) const
{
  return (region == _place.region) 
      && (registrationPoint == _place.registrationPoint)
      && (district == _place.district)
      && (street == _place.street)
      && (flat == _place.flat)
      && (house == _place.house);
}
