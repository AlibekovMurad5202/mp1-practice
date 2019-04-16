#ifndef __TIME_AND_DATE_H__
#define __TIME_AND_DATE_H__

#define UINT unsigned int

#include "MyExceptions.h"

class Time
{
public:
  Time();
  Time(UINT _hours, UINT _minutes);
  Time(const Time & _time);
  ~Time();

  UINT getHours();
  UINT getMinuts();

  void setHours(UINT _hours);
  void setMinutes(UINT _minutes);

private:
  UINT hours;
  UINT minutes;
};

class TaskDate
{
public:
  TaskDate();
  TaskDate(UINT _day, UINT _month, UINT _year);
  TaskDate(const TaskDate & _date);
  ~TaskDate();

  bool operator== (const TaskDate& _date) const;
  const TaskDate & operator=(const TaskDate & _date);

  UINT getDay();
  UINT getMonth();
  UINT getYear();

  void setDay(UINT _day);
  void setMonth(UINT _month);
  void setYear(UINT _year);

private:
  UINT day;
  UINT month;
  UINT year;
};

#endif // !__TIME_AND_DATE_H__
