#include "Container.h"

#define PRINT(a, b) std::cout << std::endl; \
        for(int i = 0; i < a; i++) std::cout << b[i] << std::endl; 

int main()
{
  Container<int, 4> c1;
  Container<int, 4> c2;
  Container<int, 4> c3(c2);
  try
  {
    try
    {
      c1.Delete(9);
    }
    catch (MyException const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine();
      std::cout << "\nerrorFile:" << e.errorFile();
    }
    std::cout << c3.IsFull() << std::endl;
    std::cout << c3.IsEmpty() << std::endl;
    c3.Add(3);
    c3.Add(9);
    c3.Add(7);
    std::cout << c3.IsEmpty() << std::endl;
    std::cout << c3.Find(9) << std::endl;
    PRINT(c3.getCount(), c3);
    c3[0] = 4;
    PRINT(c3.getCount(), c3);
    c3.Add(11);
    PRINT(c3.getCount(), c3);
    try
    {
      c3.Add(14);
      PRINT(c3.getCount(), c3);
    }
    catch (MyException const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine();
      std::cout << "\nerrorFile:" << e.errorFile();
    }
    try
    {
      c3[-1] = 0;
    }
    catch (MyException const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine();
      std::cout << "\nerrorFile:" << e.errorFile();
    }
    c3.Delete(9);
    PRINT(c3.getCount(), c3);
  }
  catch (MyException const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "Reason: " << e.why() << std::endl;
    std::cout << "errorLine: " << e.errorLine();
    std::cout << "\nerrorFile:" << e.errorFile();
  }
  catch (...)
  {
    std::cout << std::endl << "I don't know what was happened. I'm scared. \
      I cann't fix it. I'm just a computer. :(" << std::endl;
  }

  return 0;
}