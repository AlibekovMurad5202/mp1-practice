#ifndef __TASKS_H__
#define __TASKS_H__

#include "TimeAndDate.h"

class Task
{
public:
    std::string toDo;
    TaskDate date;
    Time _time;
    UINT duration;

    Task();
    Task(const std::string _toDo, TaskDate _date);
    Task(const std::string _toDo, UINT _day, UINT _month, int _year);
    Task(const Task& _task);
    virtual ~Task();

    void virtual PrintTask() = 0;
};

class TaskForDay : public Task
{
public:
    TaskForDay();
    TaskForDay(const TaskForDay& _taskForDay);
    TaskForDay(const std::string _toDo, UINT _day, UINT _month, int _year);
    TaskForDay(const std::string _toDo, TaskDate _date);
    ~TaskForDay();

    void PrintTask();
    const TaskForDay& operator= (const TaskForDay& _tfd);
};

class TaskForTime : public Task
{
public:
    TaskForTime();
    TaskForTime(const std::string _toDo, TaskDate _date, UINT _duration);
    TaskForTime(const std::string _toDo, UINT _day, UINT _month, int _year, UINT _duration);
    TaskForTime(const TaskForTime& _task);
    ~TaskForTime();

    void PrintTask();
    const TaskForTime& operator= (const TaskForTime& _tft);
};

#endif // !__TASKS_H__
