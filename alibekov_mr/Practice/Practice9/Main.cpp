#include "iostream"
#include "Tasks.h"
#include "cstdio"

int main()
{
  try 
  {
    TaskForTime t1("Do anything!", TaskDate(16, 04, 2019), 5);
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