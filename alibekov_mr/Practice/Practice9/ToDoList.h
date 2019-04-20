#ifndef __TODOLIST_H__
#define __TODOLIST_H__

#include "Tasks.h"

#include "fstream"

class ToDoList
{
public:
  ToDoList();
  ToDoList(UINT _count);
  ~ToDoList();

  void Print(TaskDate _date) const;
  void Read(const char * _fileName);


  Task ** tasks;
  UINT count;
private:
};

#endif // !__TODOLIST__H__
