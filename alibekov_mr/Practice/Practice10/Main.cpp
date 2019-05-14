#include "Container.h"

#define PRINT(a, b) std::cout << std::endl; for(int i = 0; i < a; i++) std::cout << b[i] << std::endl; 
#define PRINT_P(a, b) std::cout << std::endl; for(int i = 0; i < a; i++) std::cout << *b[i] << std::endl; 

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
    catch (ExceptionEmptyContainer const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }

    std::cout << "Is container c3 full? ";
    if (c3.IsFull())
      std::cout << " Yes" << std::endl;
    else std::cout << " No" << std::endl;   

    std::cout << "Is container c3 empty? ";
    if (c3.IsEmpty())
      std::cout << " Yes" << std::endl;
    else std::cout << " No" << std::endl;

    c3.Add(3);
    c3.Add(9);
    std::cout << "Count of elements in container c3: " << c3.getCount() << std::endl;
    c3.Add(7);

    std::cout << "Is container c3 empty? ";
    if (c3.IsEmpty())
      std::cout << " Yes" << std::endl;
    else std::cout << " No" << std::endl;

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
    catch (ExceptionFullContainer const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    try
    {
      c3[-1] = 0;
    }
    catch (ExceptionOutOfRange const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    c3.Delete(9);
    PRINT(c3.getCount(), c3);
  }
  catch (MyException const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "Reason: " << e.why() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile:" << e.errorFile() << std::endl;
  }
  catch (std::exception const& e)
  {
    std::cout << e.what << std::endl;
  }



  std::cout << std::endl << "End of Container!" << std::endl << std::endl;

  
  {
    Container<int*, 4> c1;
    Container<int*, 4> c2;
    Container<int*, 4> c3(c2);
    int* a1 = new int, *a2 = new int, *a3 = new int, *a4 = new int, *a5 = new int, *a6 = new int;
    *a1 = 3;
    *a2 = 9;
    *a3 = 7;
    *a4 = 11;
    *a5 = 14;
    *a6 = 4;
    try
    {
      try
      {
        c1.Delete(a2);
      }
      catch (ExceptionEmptyContainer const& e)
      {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Reason: " << e.why() << std::endl;
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile:" << e.errorFile() << std::endl;
      }

      std::cout << "Is container c3 full? ";
      if (c3.IsFull())
        std::cout << " Yes" << std::endl;
      else std::cout << " No" << std::endl;

      std::cout << "Is container c3 empty? ";
      if (c3.IsEmpty())
        std::cout << " Yes" << std::endl;
      else std::cout << " No" << std::endl;

      c3.Add(a1);
      c3.Add(a2);
      std::cout << "Count of elements in container c3: " << c3.getCount() << std::endl;
      c3.Add(a3);

      std::cout << "Is container c3 empty? ";
      if (c3.IsEmpty())
        std::cout << " Yes" << std::endl;
      else std::cout << " No" << std::endl;

      std::cout << c3.Find(a2) << std::endl;
      PRINT_P(c3.getCount(), c3);
      *c3[0] = *a6;
      PRINT_P(c3.getCount(), c3);
      c3.Add(a4);
      PRINT_P(c3.getCount(), c3);
      try
      {
        c3.Add(a5);
        PRINT_P(c3.getCount(), c3);
      }
      catch (ExceptionFullContainer const& e)
      {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Reason: " << e.why() << std::endl;
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile:" << e.errorFile() << std::endl;
      }
      try
      {
        *c3[-1] = *a6;
      }
      catch (ExceptionOutOfRange const& e)
      {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Reason: " << e.why() << std::endl;
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile:" << e.errorFile() << std::endl;
      }
      c3.Delete(a2);
      PRINT_P(c3.getCount(), c3);
    }
    catch (MyException const& e)
    {
      std::cout << "Error: " << e.what() << std::endl;
      std::cout << "Reason: " << e.why() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << std::endl;
      std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (std::exception const& e)
    {
      std::cout << e.what << std::endl;
    }
  }

  return 0;
}