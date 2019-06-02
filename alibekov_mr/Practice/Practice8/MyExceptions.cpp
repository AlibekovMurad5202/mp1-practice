#include "MyExceptions.h"

MyException::MyException()
{
    str_what = 0;
    line = 0;
    file = 0;
}

MyException::MyException(int _line, const char* _file)
{
    str_what = 0;
    line = _line;
    file = _file;
}

MyException::MyException(const MyException& _exception)
    : str_what(_exception.what()),
    line(_exception.errorLine()),
    file(_exception.errorFile()) {}

MyException::MyException(const char* error, const char* reason, int _line, const char* _file)
    : str_what(error),
    str_why(reason),
    line(_line),
    file(_file) {}

MyException::MyException(const char* message, int _line, const char* _file)
    : str_what(message),
    line(_line),
    file(_file) {}

MyException::~MyException()
{
    line = -1;
}

ExceptionOutOfRange::ExceptionOutOfRange()
{
    str_what = "Index out of bounds!";
    str_why = "Index less than 0 or over maximum size.";
    line = -1;
    file = 0;
}

ExceptionOutOfRange::ExceptionOutOfRange(const ExceptionOutOfRange& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionOutOfRange::ExceptionOutOfRange(int _line, const char* _file)
{
    str_what = "Index out of bounds!";
    str_why = "Index less than 0 or over maximum size.";
    line = _line;
    file = _file;
}

ExceptionOutOfRange::~ExceptionOutOfRange()
{
    line = -1;
}

ExceptionUndefinedMultiplication::ExceptionUndefinedMultiplication()
{
    str_what = "Matrices can't be multiplied!";
    str_why = "The number of columns in the first does not equal the number of rows in the second.";
    line = -1;
    file = 0;
}

ExceptionUndefinedMultiplication::ExceptionUndefinedMultiplication(const ExceptionUndefinedMultiplication& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionUndefinedMultiplication::ExceptionUndefinedMultiplication(int _line, const char* _file)
{
    str_what = "Matrices can't be multiplied!";
    str_why = "The number of columns in the first does not equal the number of rows in the second.";
    line = _line;
    file = _file;
}

ExceptionUndefinedMultiplication::~ExceptionUndefinedMultiplication()
{
    line = -1;
}

ExceptionBadAlloc::ExceptionBadAlloc()
{
    str_why = 0;
    str_what = "Bad memory allocation!";
    line = -1;
    file = 0;
}

ExceptionBadAlloc::ExceptionBadAlloc(const ExceptionBadAlloc& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionBadAlloc::ExceptionBadAlloc(int _line, const char* _file)
{
    str_why = 0;
    str_what = "Bad memory allocation!";
    line = _line;
    file = _file;
}

ExceptionBadAlloc::~ExceptionBadAlloc()
{
    line = -1;
}

ExceptionEmptyMatrix::ExceptionEmptyMatrix()
{
    str_what = "Matrix is empty!";
    str_why = "The matrix was not filled.";
    line = -1;
    file = 0;
}

ExceptionEmptyMatrix::ExceptionEmptyMatrix(const ExceptionEmptyMatrix& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionEmptyMatrix::ExceptionEmptyMatrix(int _line, const char* _file)
{
    str_what = "Matrix is empty!";
    str_why = "The matrix was not filled.";
    line = _line;
    file = _file;
}

ExceptionEmptyMatrix::~ExceptionEmptyMatrix()
{
    line = -1;
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension()
{
    str_what = "Matrix has not positive dimensions!";
    str_why = "Number of columns or number of rows no more than zero.";
    line = -1;
    file = 0;
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension(const ExceptionNotPositiveDimension& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension(int _line, const char* _file)
{
    str_what = "Matrix has not positive dimensions!";
    str_why = "Number of columns or number of rows no more than zero.";
    line = _line;
    file = _file;
}

ExceptionNotPositiveDimension::~ExceptionNotPositiveDimension()
{
    line = -1;
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions()
{
    str_what = "Matrices have different dimensions!";
    str_why = "Number of columns or rows in the first matrix, respectively, is not equal to the number of columns or rows in the second matrix.";
    line = -1;
    file = 0;
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions(const ExceptionDifferentDimensions& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions(int _line, const char* _file)
{
    str_what = "Matrices have different dimensions!";
    str_why = "Number of columns or rows in the first matrix, respectively, is not equal to the number of columns or rows in the second matrix.";
    line = _line;
    file = _file;
}

ExceptionDifferentDimensions::~ExceptionDifferentDimensions()
{
    line = -1;
};
