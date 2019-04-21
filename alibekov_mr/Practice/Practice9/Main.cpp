#include "iostream"
#include "Tasks.h"
#include "ToDoList.h"
#include "cstdio"

int main()
{
  try
  {
    std::ofstream newToDoFile("example.txt");
    newToDoFile << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TO DO LIST ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    newToDoFile << " Number of tasks: 4\n";
    newToDoFile << "|---------------------------- TASKS -------------------------------------------|\n";
    newToDoFile << " Buy a movie ticket#1! : April 21, 2019.\n";
    newToDoFile << " Buy a movie ticket#2! : April 21, 2019.\n";
    newToDoFile << " Go to the movie! : May 1, 2019. Begins at 17:45. Duration is 185 minutes.\n";
    newToDoFile << " To do smth in the past! : June 11, 3011 BC.\n";
    newToDoFile << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
    newToDoFile.close();
  }
  catch (ExceptionFileIsNotOpen const & e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "Reason: " << e.why() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile:" << e.errorFile() << std::endl;
  }
  do
  {
    try 
    {
      ToDoList td;
      td.Read("example.txt");
      for (int i = 0; i < td.count; i++)
      {
        td.tasks[i]->PrintTask();
      }
      std::cout << "\n";
      td.Print(TaskDate(21, 4, 2019));
      td.Print(TaskDate(1, 5, 2019));
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
    catch (Exception404 const & e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (ExceptionTaskUndefined const & e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (ExceptionTaskDateUndefined const & e)
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