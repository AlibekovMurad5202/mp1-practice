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
      ToDoList td;
      /*
      TaskDate td2(2, 4, 2000);
      td.Print(td2);
      */
      TaskForDay t1("To do smth!", 9, 1, -1344);
      t1.PrintTask();
      TaskForTime t2("To do Smth!", 20, 4, 2019, 13);
      t2.PrintTask();
      std::cout << "\n\n\n\n\n\n\n";

      td.Read("c:\\path\\test.txt");

    }
    catch (ExceptionOutOfRange const & e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (ExceptionFileIsNotOpen const & e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (...)
    {
      std::cout << std::endl << "I don't know what was happened. I'm scared. \
      I cann't fix it. I'm just a computer. :(" << std::endl;
    }
    break;
  } while (1);
  
  system("pause");
  return 0;
}