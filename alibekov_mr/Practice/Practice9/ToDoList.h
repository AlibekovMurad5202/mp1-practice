#ifndef __TODOLIST_H__
#define __TODOLIST_H__

#include "Tasks.h"
#include "fstream"

class ToDoList
{
public:
    Task** tasks;
    UINT count;

    ToDoList();
    ToDoList(UINT _count);
    ~ToDoList();

    void Print(TaskDate _date) const;
    void Read(const std::string _fileName);
};

#endif // !__TODOLIST__H__
