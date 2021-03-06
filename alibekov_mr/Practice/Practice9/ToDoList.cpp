#include "ToDoList.h"

ToDoList::ToDoList()
{
  tasks = nullptr;
  count = 0;
}

ToDoList::ToDoList(UINT _count)
{
  count = _count;
  tasks = new Task*[count];
}

ToDoList::~ToDoList()
{
  for (UINT i = 0; i < count; i++)
    if(tasks[i] != nullptr)
      delete tasks[i];
  if(tasks != nullptr) 
    delete[] tasks;
  count = 0;
}

void ToDoList::Print(TaskDate _date) const
{
  _date.Print();
  bool smthIs = false;
  std::cout << std::endl;
  for (UINT i = 0; i < count; i++)
  {
    if (tasks[i]->date == _date) 
    {
      tasks[i]->PrintTask();
      smthIs = true;
    }
  }
  if (!smthIs)
    std::cout << "You have not tasks for this date! Relax! :)" << std::endl;
}

void ToDoList::Read(const char * _fileName)
{
  using namespace std;

  ifstream toDoFile;
  toDoFile.open(_fileName);
  if (!toDoFile.is_open())
  {
    toDoFile.close();
    throw ExceptionFileIsNotOpen(__LINE__, __FILE__);
  }

  char str[255];
  toDoFile.getline(str, 255);
  if (toDoFile) cout << str << endl;

  ios::pos_type currentPos = toDoFile.tellg();

  toDoFile.ignore(255, ':');
  UINT _countOfTasks;
  toDoFile >> _countOfTasks;

  toDoFile.seekg(currentPos);

  toDoFile.getline(str, 255);
  cout << str << endl;
  toDoFile.getline(str, 255);
  cout << str << endl;

  count = _countOfTasks;
  tasks = new Task*[count];

  for (UINT i = 0; i < count; i++)
  {    
    ios::pos_type startPos = toDoFile.tellg();
    toDoFile.ignore(255, '.');
    char s;
    toDoFile.get(s);
    if (s == '\n')
      tasks[i] = new TaskForDay();
    else
      tasks[i] = new TaskForTime();
    toDoFile.seekg(startPos);

    startPos = toDoFile.tellg();
    toDoFile.ignore(255, ':');
    ios::pos_type endPos = toDoFile.tellg();
    toDoFile.seekg(startPos);
    toDoFile.get(str, endPos - startPos - 1);
    int k = 0;
    while (str[k] != 0)
      tasks[i]->toDo[k] = str[k++];
    tasks[i]->toDo[k] = 0;

    toDoFile.ignore(2);

    char _monthName[255];
    toDoFile >> _monthName;

    tasks[i]->date.setMonth(_monthName);

    {
      int _day;
      toDoFile >> _day;
      tasks[i]->date.setDay(_day);
    }
    toDoFile.ignore(2);
    {
      int _year;
      toDoFile >> _year;
      char next;
      toDoFile >> next;
      if ((next != '.') && (s == '\n'))
      { 
        _year *= -1;
        toDoFile.ignore(2);
      }
      tasks[i]->date.setYear(_year);
    }

    if (s != '\n')
    {
      toDoFile.ignore(11);
      {
        int _hours;
        toDoFile >> _hours;
        tasks[i]->_time.setHours(_hours);
        toDoFile.ignore(1);
        int _minutes;
        toDoFile >> _minutes;
        tasks[i]->_time.setMinutes(_minutes);
      }
      toDoFile.ignore(14);
      {
        int _duration;
        toDoFile >> _duration;
        tasks[i]->duration = _duration;
      }
      toDoFile.ignore(255, '.');
    }

    toDoFile.ignore(1);

  }

  for (UINT i = 0; i < count; i++)
  {
    tasks[i]->PrintTask();
  }

  toDoFile.getline(str, 255);
  cout << str << endl;
  toDoFile.close();
}
