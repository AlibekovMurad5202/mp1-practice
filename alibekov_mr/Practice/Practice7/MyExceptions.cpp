#include "MyExceptions.h"

MyException::MyException()
{
    str_what = 0; line = 0; file = 0;
}

MyException::MyException(int _line, const char* _file)
{
    str_what = 0; line = _line; file = _file;
}

MyException::MyException(const MyException& _exception)
    : str_what(_exception.what()),
    line(_exception.errorLine()),
    file(_exception.errorFile()) {}

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
    line = -1;
    file = 0;
}

ExceptionOutOfRange::ExceptionOutOfRange(const ExceptionOutOfRange& _exception)
{
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionOutOfRange::ExceptionOutOfRange(int _line, const char* _file)
{
    str_what = "Index out of bounds!"; line = _line; file = _file;
}

ExceptionOutOfRange::~ExceptionOutOfRange()
{
    line = -1;
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions()
{
    str_what = "Vectors have different dimensions!"; line = -1; file = 0;
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions(const ExceptionDifferentDimensions& _exception)
{
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionDifferentDimensions::ExceptionDifferentDimensions(int _line, const char* _file)
{
    str_what = "Vectors have different dimensions!"; line = _line; file = _file;
}

ExceptionDifferentDimensions::~ExceptionDifferentDimensions()
{
    line = -1;
}

ExceptionBadAlloc::ExceptionBadAlloc()
{
    str_what = "Bad memory allocation!";
    line = -1;
    file = 0;
}

ExceptionBadAlloc::ExceptionBadAlloc(const ExceptionBadAlloc& _exception)
{
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionBadAlloc::ExceptionBadAlloc(int _line, const char* _file)
{
    str_what = "Bad memory allocation!"; line = _line; file = _file;
}

ExceptionBadAlloc::~ExceptionBadAlloc()
{
    line = -1;
}

ExceptionEmptyVector::ExceptionEmptyVector()
{
    str_what = "Vector is empty!";
    line = -1;
    file = 0;
}

ExceptionEmptyVector::ExceptionEmptyVector(const ExceptionEmptyVector& _exception)
{
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionEmptyVector::ExceptionEmptyVector(int _line, const char* _file)
{
    str_what = "Vector is empty!"; line = _line; file = _file;
}

ExceptionEmptyVector::~ExceptionEmptyVector()
{
    line = -1;
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension()
{
    str_what = "Dimension is or less than zero!";
    line = -1;
    file = 0;
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension(const ExceptionNotPositiveDimension& _exception)
{
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionNotPositiveDimension::ExceptionNotPositiveDimension(int _line, const char* _file)
{
    str_what = "Dimension is or less than zero!"; line = _line; file = _file;
}

ExceptionNotPositiveDimension::~ExceptionNotPositiveDimension()
{
    line = -1;
};
