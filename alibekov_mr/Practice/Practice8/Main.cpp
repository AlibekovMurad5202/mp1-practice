#include "Matrix.h"

int main()
{
    Matrix* m_arr = nullptr;

    try
    {
        Matrix m0;
        std::cout << m0;

        Matrix m1(3, 3);
        std::cin >> m1;
        std::cout << m1;

        try
        {
            Matrix m1_err(-3, 2);
        }
        catch (ExceptionNotPositiveDimension const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        Matrix m2(m1);
        std::cout << m2;

        try
        {
            Matrix m2_err(m0);
        }
        catch (ExceptionEmptyMatrix const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        double d_arr1[] = { 1, 2, 3 };
        Matrix m3(3, 1, d_arr1);
        std::cout << m3;

        try
        {
            Matrix m3_err(-3, 2, d_arr1);
        }
        catch (ExceptionNotPositiveDimension const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        double d_arr2[] = { 3, 7, 8, 4, 1, 2 };
        Matrix m4(2, 3, d_arr2);
        std::cout << m4;

        Matrix m5(2, 3);
        std::cin >> m5;
        std::cout << m5;

        m_arr = new Matrix[16];

        m_arr[0] = m4;
        std::cout << m_arr[0];

        m_arr[1] = m1;
        std::cout << m_arr[1];

        m_arr[2] = m3;
        std::cout << m_arr[2];

        m_arr[2] = m_arr[2];
        std::cout << m_arr[2];

        try
        {
            m_arr[3] = m0;
        }
        catch (ExceptionEmptyMatrix const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[4] = m4 + 9.;
        std::cout << m_arr[4];

        try
        {
            m_arr[5] = m0 + 1.;
        }
        catch (ExceptionEmptyMatrix const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[6] = m4 - 9.;
        std::cout << m_arr[6];

        try
        {
            m_arr[7] = m0 - 1.;
        }
        catch (ExceptionEmptyMatrix const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[8] = m4 * 9.;
        std::cout << m_arr[8];

        try
        {
            m_arr[9] = m0 * 1.;
        }
        catch (ExceptionEmptyMatrix const& e)
        {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[10] = m4 * m3;
        std::cout << m_arr[10];

        try
        {
            m_arr[11] = m3 * m1;
        }
        catch (ExceptionUndefinedMultiplication const& e) {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[12] = m4 + m5;
        std::cout << m_arr[12];

        try
        {
            m_arr[13] = m3 + m1;
        }
        catch (ExceptionDifferentDimensions const& e) {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        m_arr[14] = m4 - m5;
        std::cout << m_arr[14];

        try
        {
            m_arr[15] = m3 - m1;
        }
        catch (ExceptionDifferentDimensions const& e) {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        double q = (m1[0])[1];
        std::cout << q;

        try
        {
            double q_err = (m1[-1])[0];
        }
        catch (ExceptionOutOfRange const& e) {
            std::cout << std::endl << e.what() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }
    }
    catch (MyException const& e)
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

    delete[] m_arr;

    system("pause");
    return 0;
}