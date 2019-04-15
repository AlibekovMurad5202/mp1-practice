#include "Matrix.h"

int main()
{

  Matrix* m5 = nullptr;
  Matrix* m_arr = nullptr;

  try
  {
    Matrix m1(3, 3);
    std::cin >> m1;
    std::cout << m1;
    Matrix m2(m1);
    std::cout << m2;
    Matrix m3(3, 1);
    std::cin >> m3;
    std::cout << m3;
    Matrix m6(2, 3);
    std::cin >> m6;
    std::cout << m6;
    Matrix m4;
    m1 = m1;
    m5 = new Matrix;
    m_arr = new Matrix[3];
    for (int i = 0; i < 3; i++) {
      m_arr[i] = m2;
    }
    *m5 = m2;
    try {
      double q = (m1[-1])[0];
    }
    catch (ExceptionOutOfRange const & e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    try {
      m_arr[0] = m2 + 5;
      std::cout << m_arr[0];
    }
    catch (ExceptionEmptyMatrix const & e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    try {
      m_arr[1] = m1 + m2;
      std::cout << m_arr[1];
    }
    catch (ExceptionDifferentDimensions const & e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }

    std::cout << *m5;
    for (int i = 0; i < 3; i++) {
      std::cout << m_arr[i];
    }

    try {
      m_arr[2] = m1 * m3;
    }
    catch (ExceptionUndefinedMultiplication const & e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }

    try {
      m_arr[1] = m3 * m6;
    }
    catch (ExceptionUndefinedMultiplication const & e) {
      std::cout << e.what();
      std::cout << "errorLine: " << e.errorLine() << "\nerrorFile:" << e.errorFile();
    }
    std::cout << m1 << m3 << m_arr[2] << std::endl;

  }
  catch (MyException const & e)
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

  delete m5;
  delete[] m_arr;

  system("pause");
  return 0;
}