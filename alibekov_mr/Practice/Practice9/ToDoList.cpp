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
  
  for (UINT i = 0; i < count; i++)
  {
    tasks[i]->toDo = "B";
    tasks[i]->date.setDay(2);
    tasks[i]->date.setMonth(4);
    tasks[i]->date.setYear(2000 + i);
  }

}

ToDoList::~ToDoList()
{
  for (UINT i = 0; i < count; i++)
    delete tasks[i];
  delete[] tasks;
  count = 0;
}

void ToDoList::Print(TaskDate _date) const
{
  _date.Print();
  std::cout << std::endl;
  for (UINT i = 0; i < count; i++)
  {
    if (tasks[i]->date == _date) 
    {
      tasks[i]->PrintTask();
      std::cout << std::endl;
    }
  }
}
