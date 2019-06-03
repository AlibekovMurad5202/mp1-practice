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
    str_what = "Value out of bounds!";
    str_why = "Value does not match conditions.";
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
    str_what = "Value out of bounds!";
    str_why = "Value does not match conditions.";
    line = _line;
    file = _file;
}

ExceptionOutOfRange::~ExceptionOutOfRange()
{
    line = -1;
}

Exception404::Exception404()
{
    str_why = "File with this name is not exist.";
    str_what = "File not found!";
    line = -1;
    file = 0;
}

Exception404::Exception404(const Exception404& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

Exception404::Exception404(int _line, const char* _file)
{
    str_why = "File with this name is not exist.";
    str_what = "File not found!";
    line = _line;
    file = _file;
}

Exception404::~Exception404()
{
    line = -1;
}

ExceptionTaskUndefined::ExceptionTaskUndefined()
{
    str_what = "Task is undefined!";
    str_why = "Task without name.";
    line = -1;
    file = 0;
}

ExceptionTaskUndefined::ExceptionTaskUndefined(const ExceptionTaskUndefined& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionTaskUndefined::ExceptionTaskUndefined(int _line, const char* _file)
{
    str_what = "Task is undefined!";
    str_why = "Task without name.";
    line = _line;
    file = _file;
}

ExceptionTaskUndefined::~ExceptionTaskUndefined()
{
    line = -1;
}

ExceptionTaskDateUndefined::ExceptionTaskDateUndefined()
{
    str_what = "Task's date is undefined!";
    str_why = "Task without date.";
    line = -1;
    file = 0;
}

ExceptionTaskDateUndefined::ExceptionTaskDateUndefined(const ExceptionTaskDateUndefined& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionTaskDateUndefined::ExceptionTaskDateUndefined(int _line, const char* _file)
{
    str_what = "Task's date is undefined!";
    str_why = "Task without date.";
    line = _line;
    file = _file;
}

ExceptionTaskDateUndefined::~ExceptionTaskDateUndefined()
{
    line = -1;
}

ExceptionFileIsNotOpen::ExceptionFileIsNotOpen()
{
    str_what = "File is not open!";
    str_why = 0;
    line = -1;
    file = 0;
}

ExceptionFileIsNotOpen::ExceptionFileIsNotOpen(const ExceptionFileIsNotOpen& _exception)
{
    str_why = _exception.why();
    str_what = _exception.what();
    line = _exception.errorLine();
    file = _exception.errorFile();
}

ExceptionFileIsNotOpen::ExceptionFileIsNotOpen(int _line, const char* _file)
{
    str_what = "File is not open!";
    str_why = 0;
    line = _line;
    file = _file;
}

ExceptionFileIsNotOpen::~ExceptionFileIsNotOpen()
{
    line = -1;
};