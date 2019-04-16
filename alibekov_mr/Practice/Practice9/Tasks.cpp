#include "Tasks.h"

Time::Time()
{
  hours = 0;
  minutes = 0;
}

Time::Time(UINT _hours, UINT _minutes)
{
  if ((_minutes >= 60) || (_hours >= 24))// || (_minutes / UINT_MAX) || _hours / UINT_MAX)
    throw ExceptionOutOfRange(__LINE__, __FILE__);

  hours = _hours;
  minutes = _minutes;
}

Time::Time(const Time & _time)
{
  /*if ((_time.minutes >= 60) || (_time.hours >= 24))// || (_time.minutes / UINT_MAX) || _time.hours / UINT_MAX)
    throw ExceptionOutOfRange(__LINE__, __FILE__);*/

  hours = _time.hours;
  minutes = _time.minutes;
}

Time::~Time()
{
  hours = 0;
  minutes = 0;
}

TaskDate::TaskDate()
{
  day = 0;
  month = 0;
  year = 0;
}

TaskDate::TaskDate(UINT _day, UINT _month, UINT _year)
{
  if (_day == 0 || _month > 12 || _month == 0 || _day > 31 ||
    (_day == 31 && (_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11)) ||
    (_month == 2 && (_day > (UINT)((_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0) ? 29 : 28))))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  day = _day;
  month = _month;
  year = _year;
}

TaskDate::TaskDate(const TaskDate & _date)
{
  /*if (_date.day == 0 || _date.month > 12 || _date.month == 0 || _date.day > 31 ||
    (_date.day == 31 && (_date.month == 2 || _date.month == 4 || _date.month == 6 || _date.month == 9 || _date.month == 11)) ||
    (_date.month == 2 && (_date.day > ((_date.year % 4 == 0 && _date.year % 100 != 0 || _date.year % 400 == 0) ? 29 : 28))))
    throw ExceptionOutOfRange(__LINE__, __FILE__);*/
  day = _date.day;
  month = _date.month;
  year = _date.year;
}

TaskDate::~TaskDate()
{
  day = 0;
  month = 0;
  year = 0;
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

Task::Task()
{
  toDo = nullptr;
  date = TaskDate();
}

Task::Task(const char * _toDo, TaskDate _date)
{
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
  toDo = _toDo;
  date = _date;
}

TaskForDay::~TaskForDay()
{}

void TaskForDay::PrintTask()
{
  std::cout << toDo << " : " << date.getDay() << ", " << date.getMonth() << ", " << date.getYear() << std::endl;
}
