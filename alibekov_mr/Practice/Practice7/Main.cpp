#include "Vector.h"

int main() {
  Vector v1(3);
  Vector v2(v1);
  Vector v3(2);
  Vector v4;
  Vector* v5 = new Vector[10];
  v5[1] = v2;
  try {
    double q = v1[5];
  }
  catch (ExceptionOutOfRange e){
    std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
  }
  v2 += 5;
  v3.Print();
  
  try {
    v4 = v1 + v2;
    v4.Print();
  }
  catch (ExceptionDifferentDimensions e) {
    std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
  }
  
 /*
  v1 = v3 = v2;
  //std::cout << v.Length();
  v1.Print();
  v2.Print();
  v3.Print();*/

  v5->Print();
 // std::cout << v5;
  delete v5;
  system("pause");
  return 0;
}