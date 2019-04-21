#ifndef __TASKS_H__
#define __TASKS_H__

#include "iostream"
#include "TimeAndDate.h"

class Task
{
public:
  char toDo[255];
  TaskDate date;
  Time _time;
  UINT duration;

  Task();
  Task(const char * _toDo, TaskDate _date);
  Task(const char * _toDo, UINT _day, UINT _month, int _year);
  Task(const Task& _task);
  virtual ~Task();

  void virtual PrintTask() = 0 ;

private:
};

class TaskForDay : public Task
{
public:
  TaskForDay();
  TaskForDay(const TaskForDay & _taskForDay);
  TaskForDay(const char * _toDo, UINT _day, UINT _month, int _year);
  TaskForDay(const char * _toDo, TaskDate _date);
  ~TaskForDay();

  void PrintTask();
  const TaskForDay & operator= (const TaskForDay & _tfd);
};

class TaskForTime : public Task
{
public:
  TaskForTime();
  TaskForTime(const char * _toDo, TaskDate _date, UINT _duration);
  TaskForTime(const char * _toDo, UINT _day, UINT _month, int _year, UINT _duration);
  TaskForTime(const TaskForTime & _task);
  ~TaskForTime();

  void PrintTask();
  const TaskForTime & operator= (const TaskForTime & _tft);

private:
};

#endif // !__TASKS_H__
