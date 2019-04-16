#include "ToDoList.h"

ToDoList::ToDoList()
{
  tasks = nullptr;
  count = 0;
}

ToDoList::ToDoList(const ToDoList & _toDoList)
{

}

ToDoList::~ToDoList()
{
  for (int i = 0; i < count; i++)
    delete tasks[i];
  delete[] tasks;
}
