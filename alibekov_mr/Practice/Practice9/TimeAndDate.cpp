#include "TimeAndDate.h"
#include "string"

Time::Time()
{
    setHours(0);
    setMinutes(0);
}

Time::Time(UINT _hours, UINT _minutes)
{
    setHours(_hours);
    setMinutes(_minutes);
}

Time::Time(const Time& _time)
{
    setHours(_time.hours);
    setMinutes(_time.minutes);
}

Time::~Time()
{
    setHours(0);
    setMinutes(0);
}

const Time& Time::operator=(const Time& _t)
{
    if (this != &_t)
    {
        setHours(getHours());
        setMinutes(getMinutes());
    }
    return *this;
}

void Time::Print()
{
    if (hours < 10)
        std::cout << "0";
    std::cout << hours << ":";
    if (minutes < 10)
        std::cout << "0";
    std::cout << minutes;
}

UINT Time::getHours()
{
    return hours;
}

UINT Time::getMinutes()
{
    return minutes;
}

void Time::setHours(UINT _hours)
{
    if ((_hours < 0) || (_hours >= 24))
        throw ExceptionOutOfRange(__LINE__, __FILE__);
    hours = _hours;
}

void Time::setMinutes(UINT _minutes)
{
    if ((_minutes >= 60) || (_minutes < 0))
        throw ExceptionOutOfRange(__LINE__, __FILE__);
    minutes = _minutes;
}

TaskDate::TaskDate()
{
    setDay(1);
    setMonth(1);
    setYear(1970);
}

TaskDate::TaskDate(UINT _day, UINT _month, int _year)
{
    setDay(_day);
    setMonth(_month);
    setYear(_year);
}

TaskDate::TaskDate(const TaskDate & _date)
{
    setDay(_date.day);
    setMonth(_date.month);
    setYear(_date.year);
}

TaskDate::~TaskDate()
{
    setDay(1);
    setMonth(1);
    setYear(1970);
}

bool TaskDate::operator==(const TaskDate & _date) const
{
    if (this == &_date)
        return true;
    return ((_date.day == day) && (_date.month == month) && (_date.year == year));
}

const TaskDate & TaskDate::operator=(const TaskDate & _date)
{
    if (this != &_date)
    {
        day = _date.day;
        month = _date.month;
        year = _date.year;
    }
    return *this;
}

void TaskDate::Print()
{
    std::cout << months[month] << " " << day << ", ";
    if (year > 0)
        std::cout << year << ".";
    else
        std::cout << (-1) * year << " BC.";
}

UINT TaskDate::getDay()
{
    return day;
}

UINT TaskDate::getMonth()
{
    return month;
}

int TaskDate::getYear()
{
    return year;
}

void TaskDate::setDay(UINT _day)
{
    if (_day == 0 || _day > 31 ||
    (_day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) ||
    (month == 2 && (_day > (UINT)((getYear() % 4 == 0 && getYear() % 100 != 0 || getYear() % 400 == 0) ? 29 : 28))))
        throw ExceptionOutOfRange(__LINE__, __FILE__);
    day = _day;
}

void TaskDate::setMonth(UINT _month)
{
    if ((_month < 1) || (_month > 12))
        throw ExceptionOutOfRange(__LINE__, __FILE__);
    month = _month;
}

void TaskDate::setMonth(std::string _monthName)
{
    months[0] == _monthName;
    for (UINT j = 1; j < 14; j++)
    {
        if (months[j] == _monthName)
        {
            setMonth(j);
            break;
        }
    }
}

void TaskDate::setYear(int _year)
{
    year = _year;
}