#include "Vector.h"

int main() {

    Vector* v7 = nullptr;
    Vector* v_arr = nullptr;

/*    Vector v1;
    try {
        std::cout << v1.Length();
    }
    catch (ExceptionEmptyVector const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    Vector v2(2);
    try {
        v2[0] = 1.;
        v2[1] = 2.;
        double q = v2[-1];
    }
    catch (ExceptionOutOfRange const& e) {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }
    std::cout << v2;

    Vector v3(3);
    v3[0] = v2[1];
    v3[1] = -2.;
    v3[2] = -3.;
    std::cout << v3;

    try {
        Vector v3_err(-2);
    }
    catch (ExceptionNotPositiveDimension const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    double d_arr[] = { 0, 1, 2, 3 };
    int d_count = 4;
    Vector v4(d_count, d_arr);
    std::cout << v4;

    try {
        Vector v4_err(-4, d_arr);
    }
    catch (ExceptionNotPositiveDimension const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    Vector v5(v4);
    std::cout << v5;

    try {
        Vector v5_err(v1);
    }
    catch (ExceptionEmptyVector const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    Vector v6(6);
    std::cin >> v6;
    v6.Print();

    v7 = new Vector;
    v_arr = new Vector[13];

    v_arr[0] = v2;
    std::cout << v_arr[0];
    
    v_arr[1] = v3;
    std::cout << v_arr[1];
    
    v_arr[1] = v_arr[1];
    std::cout << v_arr[1];
    
    try {
        v_arr[2] = v1;
    }
    catch (ExceptionEmptyVector const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }
    
    v_arr[3] = v_arr[0] + v2;
    std::cout << v_arr[3];
    std::cout << v_arr[3].Length();

    try {
        v_arr[4] = v_arr[0] + v3;
    }
    catch (ExceptionDifferentDimensions const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    v_arr[5] = v_arr[0] - v2;
    std::cout << v_arr[5];

    try {
        v_arr[6] = v_arr[0] - v3;
    }
    catch (ExceptionDifferentDimensions const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    double rez1 = v_arr[0] * v_arr[3];
    std::cout << rez1;

    try {
        double rez2 = v_arr[0] * v3;
    }
    catch (ExceptionDifferentDimensions const& e)
    {
        std::cout << e.what();
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile: " << e.errorFile() << std::endl;
    }

    v_arr[7] = v3;
    v_arr[7] += 7;
    std::cout << v_arr[7];

    v_arr[8] = v3;
    v_arr[8] -= 8;
    std::cout << v_arr[8];

    v_arr[9] = v3;
    v_arr[9] *= 9;
    std::cout << v_arr[9];

    v_arr[10] = v2 + 10.;
    std::cout << v_arr[10];

    v_arr[11] = v2 - 11.;
    std::cout << v_arr[11];

    v_arr[12] = v2 * 12.;
    std::cout << v_arr[12];*/

    try
    {
        Vector v1;
        try {
            std::cout << v1.Length();
        }
        catch (ExceptionEmptyVector const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        Vector v2(2);
        v2[0] = 1.;
        v2[1] = 2.6;
        std::cout << v2;

        try {
            double q = v2[-1];
        }
        catch (ExceptionOutOfRange const& e) {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        Vector v3(3);
        v3[0] = v2[1];
        v3[1] = -2.;
        v3[2] = -3.;
        std::cout << v3;

        try {
            Vector v3_err(-2);
        }
        catch (ExceptionNotPositiveDimension const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        double d_arr[] = { 0, 1, 2, 3 };
        int d_count = 4;
        Vector v4(d_count, d_arr);
        std::cout << v4;

        try {
            Vector v4_err(-4, d_arr);
        }
        catch (ExceptionNotPositiveDimension const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        Vector v5(v4);
        std::cout << v5;

        try {
            Vector v5_err(v1);
        }
        catch (ExceptionEmptyVector const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        Vector v6(6);
        std::cin >> v6;
        v6.Print();

        v7 = new Vector;
        v_arr = new Vector[13];

        v_arr[0] = v2;
        std::cout << v_arr[0];

        v_arr[1] = v3;
        std::cout << v_arr[1];

        v_arr[1] = v_arr[1];
        std::cout << v_arr[1];

        try {
            v_arr[2] = v1;
        }
        catch (ExceptionEmptyVector const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        v_arr[3] = v_arr[0] + v2;
        std::cout << v_arr[3];
        std::cout << v_arr[3].Length();

        try {
            v_arr[4] = v_arr[0] + v3;
        }
        catch (ExceptionDifferentDimensions const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        v_arr[5] = v_arr[0] - v2;
        std::cout << v_arr[5];

        try {
            v_arr[6] = v_arr[0] - v3;
        }
        catch (ExceptionDifferentDimensions const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        double rez1 = v_arr[0] * v_arr[3];
        std::cout << rez1;

        try {
            double rez2 = v_arr[0] * v3;
        }
        catch (ExceptionDifferentDimensions const& e)
        {
            std::cout << e.what();
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile: " << e.errorFile() << std::endl;
        }

        v_arr[7] = v3;
        v_arr[7] += 7;
        std::cout << v_arr[7];

        v_arr[8] = v3;
        v_arr[8] -= 8;
        std::cout << v_arr[8];

        v_arr[9] = v3;
        v_arr[9] *= 9;
        std::cout << v_arr[9];

        v_arr[10] = v2 + 10.;
        std::cout << v_arr[10];

        v_arr[11] = v2 - 11.;
        std::cout << v_arr[11];

        v_arr[12] = v2 * 12.;
        std::cout << v_arr[12];
    }
    catch (MyException const& e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    catch (...)
    {
        std::cout << std::endl << "I don't know what was happened. I'm scared. \
        I cann't fix it. I'm just a computer. :(" << std::endl;
    }

    delete v7;
    delete[] v_arr;

    system("pause");
    return 0;
}