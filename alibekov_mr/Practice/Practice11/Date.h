#ifndef __DATE_H__
#define __DATE_H__

#define UINT unsigned int

#include "MyExceptions.h"
#include "iostream"
#include "cstdio"

static const char* months[13] = { 0, "January" , "February", "March", "April", "May",
       "June", "July", "August", "September", "October", "November", "December" };

class Date
{
public:
  Date();
  Date(UINT _day, UINT _month, int _year);
  Date(const TaskDate & _date);
  ~Date();

  bool operator== (const Date& _date) const;
  const TaskDate & operator=(const Date & _date);

  void Print();

  UINT getDay();
  UINT getMonth();
  int getYear();

  void setDay(UINT _day);
  void setMonth(UINT _month);
  void setMonth(char *_monthName);
  void setYear(int _year);

private:
  UINT day;
  UINT month;
  int year;
};

#endif