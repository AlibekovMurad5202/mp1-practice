#include "MyExceptions.h"

MyException::MyException()
{
  str_what = 0;
  line = 0;
  file = 0;
}

MyException::MyException(int _line, const char *_file)
{
  str_what = 0;
  line = _line;
  file = _file;
}

MyException::MyException(const MyException& _exception)
  : str_what(_exception.what()),
  line(_exception.errorLine()),
  file(_exception.errorFile()) {}

MyException::MyException(const char * error, const char * reason, int _line, const char * _file)
  : str_what(error),
  str_why(reason),
  line(_line),
  file(_file) {}

MyException::MyException(const char* message, int _line, const char *_file)
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
  str_why = "Index less than 0 or over maximum value.";
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

ExceptionOutOfRange::ExceptionOutOfRange(int _line, const char *_file)
{
  str_what = "Index out of bounds!";
  str_why = "Index less than 0 or over maximum value.";
  line = _line;
  file = _file;
}

ExceptionOutOfRange::~ExceptionOutOfRange()
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

ExceptionBadAlloc::ExceptionBadAlloc(int _line, const char *_file)
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

ExceptionTaskWithoutName::ExceptionTaskWithoutName()
{
  str_what = "Matrix is empty!";
  str_why = "The matrix was not filled.";
  line = -1;
  file = 0;
}

ExceptionTaskWithoutName::ExceptionTaskWithoutName(const ExceptionTaskWithoutName& _exception)
{
  str_why = _exception.why();
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionTaskWithoutName::ExceptionTaskWithoutName(int _line, const char *_file)
{
  str_what = "Matrix is empty!";
  str_why = "The matrix was not filled.";
  line = _line;
  file = _file;
}

ExceptionTaskWithoutName::~ExceptionTaskWithoutName()
{
  line = -1;
}

ExceptionTaskWithoutDate::ExceptionTaskWithoutDate()
{
  str_what = "Matrix has not positive dimensions!";
  str_why = "Number of columns or number of rows no more than zero.";
  line = -1;
  file = 0;
}

ExceptionTaskWithoutDate::ExceptionTaskWithoutDate(const ExceptionTaskWithoutDate& _exception)
{
  str_why = _exception.why();
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionTaskWithoutDate::ExceptionTaskWithoutDate(int _line, const char *_file)
{
  str_what = "Matrix has not positive dimensions!";
  str_why = "Number of columns or number of rows no more than zero.";
  line = _line;
  file = _file;
}

ExceptionTaskWithoutDate::~ExceptionTaskWithoutDate()
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

ExceptionDifferentDimensions::ExceptionDifferentDimensions(int _line, const char *_file)
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
