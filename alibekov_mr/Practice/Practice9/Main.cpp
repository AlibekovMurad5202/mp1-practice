#include "iostream"
#include "Tasks.h"

int main()
{
  try 
  {
    TaskForDay t1(nullptr, TaskDate(16, 04, 2019));
    t1.PrintTask();
  }
  catch (ExceptionOutOfRange const & e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "Reason: " << e.why() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile:" << e.errorFile() << std::endl;
  }

  system("pause");
  return 0;
}