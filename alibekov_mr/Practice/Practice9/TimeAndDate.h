#ifndef __TIME_AND_DATE_H__
#define __TIME_AND_DATE_H__

#define UINT unsigned int

#include "MyExceptions.h"
#include "iostream"
#include "cstdio"
#include "string"

static const std::string months[13] = { 0, "January" , "February", "March", "April", "May",
       "June", "July", "August", "September", "October", "November", "December" };

class Time
{
public:
    Time();
    Time(UINT _hours, UINT _minutes);
    Time(const Time& _time);
    ~Time();

    const Time& operator= (const Time& _t);

    void Print();

    UINT getHours();
    UINT getMinutes();

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
    TaskDate(UINT _day, UINT _month, int _year);
    TaskDate(const TaskDate& _date);
    ~TaskDate();

    bool operator== (const TaskDate& _date) const;
    const TaskDate& operator=(const TaskDate& _date);

    void Print();

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

#endif // !__TIME_AND_DATE_H__