#ifndef __TASKS_H__
#define __TASKS_H__

#include "MyExceptions.h"
#include "iostream"
#define UINT unsigned int

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

class Task
{
public:
  const char* toDo;
  TaskDate date;

  Task();
  Task(const char * _toDo, TaskDate _date);
  Task(const Task& _task);
  ~Task();

  void virtual PrintTask() = 0 ;

private:

};

class TaskForDay : public Task
{
public:
  TaskForDay();
  TaskForDay(const TaskForDay & _taskForDay);
  TaskForDay(const char * _toDo, TaskDate _date);
  ~TaskForDay();

  void PrintTask();

};

class TaskForTime : public Task
{
public:
  TaskForTime();
  TaskForTime(const char * _toDo, TaskDate _date, UINT _duration);
  TaskForTime(const TaskForTime & _task);
  ~TaskForTime();

  void PrintTask();

private:
  Time _time;
  UINT duration;
};

#endif // !__TASKS_H__
