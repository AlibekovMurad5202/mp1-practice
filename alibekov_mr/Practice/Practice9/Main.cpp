#include "iostream"
#include "Tasks.h"
#include "ToDoList.h"
#include "cstdio"

int main()
{
  do
  {
    try 
    {
      ToDoList td(2);
      TaskDate td2(2, 4, 2000);
      td.Print(td2);

      TaskForDay t1("To do smth!", 9, 1, -1344);
      t1.PrintTask();
      TaskForTime t2("To do Smth!", 20, 4, 2019, 13);
      t2.PrintTask();
    }
    catch (ExceptionOutOfRange const & e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    break;
  } while (1);
  
  system("pause");
  return 0;
}