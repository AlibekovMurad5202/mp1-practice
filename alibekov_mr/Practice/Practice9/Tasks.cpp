#include "Tasks.h"

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

Time::Time(const Time & _time)
{
  setHours(_time.hours);
  setMinutes(_time.minutes);
}

Time::~Time()
{
  setHours(0);
  setMinutes(0);
}

UINT Time::getHours() 
{ 
  return hours; 
}

UINT Time::getMinuts() 
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

TaskDate::TaskDate(UINT _day, UINT _month, UINT _year)
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
  if ((_date.day == day) && (_date.month == month) && (_date.year == year))
    return true;
  return false;
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

UINT TaskDate::getDay() 
{
  return day; 
}

UINT TaskDate::getMonth() 
{ 
  return month; 
}

UINT TaskDate::getYear() 
{ 
  return year; 
}

void TaskDate::setDay(UINT _day)
{
  if (_day == 0 || _day > 31 ||
    (_day == 31 && (getMonth() == 2 || getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)) ||
    (getMonth() == 2 && (_day > (UINT)((getYear() % 4 == 0 && getYear() % 100 != 0 || getYear() % 400 == 0) ? 29 : 28))))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  day = _day;
}

void TaskDate::setMonth(UINT _month)
{
  if ((_month < 1) || (_month > 12))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  month = _month;
}

void TaskDate::setYear(UINT _year)
{
  year = _year;
}

Task::Task()
{
  toDo = nullptr;
  date = TaskDate();
}

Task::Task(const char * _toDo, TaskDate _date)
{
  if (_toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  toDo = _toDo;
  date = _date;
}

Task::Task(const Task & _task)
{
  toDo = _task.toDo;
  date = _task.date;
}

Task::~Task()
{
  toDo = nullptr;
  date = TaskDate();
}

TaskForDay::TaskForDay()
{}

TaskForDay::TaskForDay(const TaskForDay & _taskForDay)
{
  toDo = _taskForDay.toDo;
  date = _taskForDay.date;
}

TaskForDay::TaskForDay(const char * _toDo, TaskDate _date)
{
  if (_toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  toDo = _toDo;
  date = _date;
}

TaskForDay::~TaskForDay()
{}

void TaskForDay::PrintTask()
{
  if (toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  std::cout << toDo << " : " << date.getDay() << ", " << date.getMonth() << ", " << date.getYear() << std::endl;
}

TaskForTime::TaskForTime()
{
  duration = 0;
  _time = Time();
}

TaskForTime::TaskForTime(const char * _toDo, TaskDate _date, UINT _duration)
{
  if (_toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  toDo = _toDo;
  date = _date;
  duration = _duration;
}

TaskForTime::TaskForTime(const TaskForTime & _task)
{
  if (_task.toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  toDo = _task.toDo;
  date = _task.date;
  duration = _task.duration;
}

TaskForTime::~TaskForTime()
{
  duration = 0;
  _time = Time();
}

void TaskForTime::PrintTask()
{
  if (toDo == nullptr)
    throw ExceptionTaskWithoutName(__LINE__, __FILE__);
  std::cout << toDo << " : " << date.getDay() << ", " << date.getMonth() << ", " << date.getYear() << ", ";
  std::cout << _time.getHours() << ":" << _time.getMinuts() << ". Duration: " << duration << " minutes" << std::endl;
}
