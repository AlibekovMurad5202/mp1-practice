#ifndef __DATE_H__
#define __DATE_H__

#define UINT unsigned int

#include "MyExceptions.h"
#include "iostream"
#include "cstdio"
#include "string"

static const std::string months[13] = { 0, "January" , "February", "March", "April", "May",
       "June", "July", "August", "September", "October", "November", "December" };

class Date
{
public:
  Date();
  Date(UINT _day, UINT _month, int _year);
  Date(const Date & _date);
  ~Date();

  bool operator== (const Date& _date) const;
  const Date & operator=(const Date & _date);

  void Print() const;

  UINT getDay();
  UINT getMonth();
  int getYear();

  void setDay(UINT _day);
  void setMonth(UINT _month);
  void setMonth(std::string _monthName);
  void setYear(int _year);

private:
  UINT day;
  UINT month;
  int year;
};

#endif