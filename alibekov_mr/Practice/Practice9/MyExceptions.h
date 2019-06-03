#ifndef __MY_EXCEPTIONS_H__
#define __MY_EXCEPTIONS_H__

#include <exception>

class MyException : public std::exception
{
protected:
    char s_e[20] = "Unknown exception!";
    char s_r[20] = "Unknown reason!";
    const char* str_what;
    const char* str_why;
    int line;
    const char* file;

public:
    MyException();
    MyException(int _line, const char* _file);
    MyException(const MyException& _exception);
    MyException(const char* error, const char* reason, int _line, const char* _file);
    MyException(const char* message, int _line, const char* _file);
    ~MyException();

    virtual const char* why() const { return str_why ? str_why : s_r; }
    virtual const char* what() const { return str_what ? str_what : s_e; }
    virtual int errorLine() const { return line; }
    virtual const char* errorFile() const { return file; }
};

class ExceptionOutOfRange : public MyException
{
public:
    ExceptionOutOfRange();
    ExceptionOutOfRange(const ExceptionOutOfRange& _exception);
    ExceptionOutOfRange(int _line, const char* _file);
    ~ExceptionOutOfRange();
};

class Exception404 : public MyException
{
public:
    Exception404();
    Exception404(const Exception404& _exception);
    Exception404(int _line, const char* _file);
    ~Exception404();
};

class ExceptionTaskUndefined : public MyException
{
public:
    ExceptionTaskUndefined();
    ExceptionTaskUndefined(const ExceptionTaskUndefined& _exception);
    ExceptionTaskUndefined(int _line, const char* _file);
    ~ExceptionTaskUndefined();
};

class ExceptionTaskDateUndefined : public MyException
{
public:
    ExceptionTaskDateUndefined();
    ExceptionTaskDateUndefined(const ExceptionTaskDateUndefined& _exception);
    ExceptionTaskDateUndefined(int _line, const char* _file);
    ~ExceptionTaskDateUndefined();
};

class ExceptionFileIsNotOpen : public MyException
{
public:
    ExceptionFileIsNotOpen();
    ExceptionFileIsNotOpen(const ExceptionFileIsNotOpen& _exception);
    ExceptionFileIsNotOpen(int _line, const char* _file);
    ~ExceptionFileIsNotOpen();
};

#endif // !__MY_EXCEPTIONS_H__