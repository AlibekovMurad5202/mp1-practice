#ifndef __TODOLIST_H__
#define __TODOLIST_H__

#include "Tasks.h"

class ToDoList
{
public:
  ToDoList();
  ToDoList(UINT _count);
  ~ToDoList();

  void Print(TaskDate _date) const;
  //void Read(const char * _toDo, );

private:
  Task ** tasks;
  UINT count;
};

#endif // !__TODOLIST__H__
