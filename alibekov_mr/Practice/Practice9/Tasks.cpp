#include "Tasks.h"

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
