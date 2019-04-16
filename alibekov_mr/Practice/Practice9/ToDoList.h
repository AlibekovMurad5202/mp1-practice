#ifndef __TODOLIST_H__
#define __TODOLIST_H__

#include "Tasks.h"

class ToDoList
{
public:
  ToDoList();
  ToDoList(const ToDoList & _toDoList);
  ~ToDoList();

  void Print(TaskDate _date);
  //void Read(const char * _toDo, );

private:
  Task ** tasks;
  int count;
};

#endif // !__TODOLIST__H__
