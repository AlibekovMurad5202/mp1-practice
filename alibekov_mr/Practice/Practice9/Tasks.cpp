#include "Tasks.h"

Task::Task()
{
    toDo[0] = '\0';
    date = TaskDate();
}

Task::Task(const std::string _toDo, TaskDate _date)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date = _date;
}

Task::Task(const std::string _toDo, UINT _day, UINT _month, int _year)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
}

Task::Task(const Task& _task)
{
    toDo = _task.toDo;
    date = _task.date;
}

Task::~Task()
{
    toDo[0] = 0;
    date = TaskDate();
}

TaskForDay::TaskForDay()
{}

TaskForDay::TaskForDay(const TaskForDay& _taskForDay)
{
    toDo = _taskForDay.toDo;
    date = _taskForDay.date;
}

TaskForDay::TaskForDay(const std::string _toDo, UINT _day, UINT _month, int _year)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
}

TaskForDay::TaskForDay(const std::string _toDo, TaskDate _date)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date = _date;
}

TaskForDay::~TaskForDay()
{}

void TaskForDay::PrintTask()
{
    if (toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    std::cout << toDo << " : ";
    date.Print();
    std::cout << std::endl;
}

const TaskForDay& TaskForDay::operator=(const TaskForDay& _tfd)
{
    date = _tfd.date;
    toDo = _tfd.toDo;
    return *this;
}

TaskForTime::TaskForTime()
{
    duration = 0;
    _time = Time();
}

TaskForTime::TaskForTime(const std::string _toDo, TaskDate _date, UINT _duration)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date = _date;
    duration = _duration;
}

TaskForTime::TaskForTime(const std::string _toDo, UINT _day, UINT _month, int _year, UINT _duration)
{
    if (_toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    toDo = _toDo;
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
    duration = _duration;
}

TaskForTime::TaskForTime(const TaskForTime& _task)
{
    if (_task.toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
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
    if (toDo.empty())
        throw ExceptionTaskUndefined(__LINE__, __FILE__);
    std::cout << toDo << " : ";
    date.Print();
    std::cout << " Begins at ";
    _time.Print();
    std::cout << ". Duration is " << duration;
    if (duration == 1)
        std::cout << " minute." << std::endl;
    else
        std::cout << " minutes." << std::endl;
}

const TaskForTime& TaskForTime::operator=(const TaskForTime & _tft)
{
    date = _tft.date;
    toDo = _tft.toDo;
    _time = _tft._time;
    duration = _tft.duration;
    return *this;
}