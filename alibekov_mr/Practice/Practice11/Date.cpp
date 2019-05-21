#include "Date.h"

Date::Date()
{
  setDay(1);
  setMonth(1);
  setYear(1970);
}

Date::Date(UINT _day, UINT _month, int _year)
{
  setDay(_day);
  setMonth(_month);
  setYear(_year);
}

Date::Date(const Date & _date)
{
  setDay(_date.day);
  setMonth(_date.month);
  setYear(_date.year);
}

Date::~Date()
{
  setDay(1);
  setMonth(1);
  setYear(1970);
}

bool Date::operator==(const Date & _date) const
{
  if (this == &_date)
    return true;
  return ((_date.day == day) && (_date.month == month) && (_date.year == year));
}

const Date & Date::operator=(const Date & _date)
{
  if (this != &_date)
  {
    day = _date.day;
    month = _date.month;
    year = _date.year;
  }
  return *this;
}

void Date::Print() const
{
  std::cout << months[month] << " " << day << ", ";
  if (year > 0)
    std::cout << year << ".";
  else
    std::cout << (-1) * year << " BC.";
}

UINT Date::getDay()
{
  return day;
}

UINT Date::getMonth()
{
  return month;
}

int Date::getYear()
{
  return year;
}

void Date::setDay(UINT _day)
{
  if (_day == 0 || _day > 31 ||
    (_day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) ||
    (month == 2 && (_day > (UINT)((getYear() % 4 == 0 && getYear() % 100 != 0 || getYear() % 400 == 0) ? 29 : 28))))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  day = _day;
}

void Date::setMonth(UINT _month)
{
  if ((_month < 1) || (_month > 12))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  month = _month;
}

void Date::setMonth(std::string _monthName)
{
  for (UINT j = 1; j < 14; j++)
  {
    bool b = false;
    int p = 0;
    while ((months[j])[p])
      if ((months[j])[p] != _monthName[p++])
      {
        b = true;
        break;
      }
    if (!b)
    {
      setMonth(j);
      break;
    }
  }
}

void Date::setYear(int _year)
{
  year = _year;
}