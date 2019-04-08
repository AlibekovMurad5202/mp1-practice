#include "Vector.h"

int main() {
  try
  {
    Vector v1(3);
    Vector v2(v1);
    Vector v3(2);
    Vector v4;
    Vector* v5 = new Vector;
    Vector* v_arr = new Vector[10];
    for (int i = 0; i < 10; i++) {
      v_arr[i] = v2;
    }
    *v5 = v2;
    try {
      double q = v1[-1];
    }
    catch (ExceptionOutOfRange e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    try {
      v2 += 5;
    }
    catch (ExceptionEmptyVector e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    v3.Print();
    try {
      v_arr[9] = v1 + v2;
      std::cout << v_arr[9];
    }
    catch (ExceptionDifferentDimensions e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }

    v5->Print();
    for (int i = 0; i < 10; i++) {
      std::cout << v_arr[i];
    }

    std::cout << v_arr[3].Length();

    delete v5;
    delete[] v_arr;
    }
    catch (MyException e)
    {
      std::cout << e.what() << std::endl;
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    catch (...) 
    {
      std::cout << std::endl << "I don't know what was happened. I'm scared. \
        I cann't fix it. I'm just a computer. :(" << std::endl;
    }

  system("pause");
  return 0;
}