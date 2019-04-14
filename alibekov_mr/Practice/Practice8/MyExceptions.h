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
  MyException(int _line, const char *_file);
  MyException(const MyException& _exception);
  MyException(const char* error, const char* reason, int _line, const char *_file);
  MyException(const char* message, int _line, const char *_file);
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
  ExceptionOutOfRange(int _line, const char *_file);
  ~ExceptionOutOfRange();
};

class ExceptionUndefinedMultiplication : public MyException
{
public:
  ExceptionUndefinedMultiplication();
  ExceptionUndefinedMultiplication(const ExceptionUndefinedMultiplication& _exception);
  ExceptionUndefinedMultiplication(int _line, const char *_file);
  ~ExceptionUndefinedMultiplication();
};

class ExceptionBadAlloc : public MyException
{
public:
  ExceptionBadAlloc();
  ExceptionBadAlloc(const ExceptionBadAlloc& _exception);
  ExceptionBadAlloc(int _line, const char *_file);
  ~ExceptionBadAlloc();
};

class ExceptionEmptyMatrix : public MyException
{
public:
  ExceptionEmptyMatrix();
  ExceptionEmptyMatrix(const ExceptionEmptyMatrix& _exception);
  ExceptionEmptyMatrix(int _line, const char *_file);
  ~ExceptionEmptyMatrix();
};

class ExceptionNotPositiveDimension : public MyException
{
public:
  ExceptionNotPositiveDimension();
  ExceptionNotPositiveDimension(const ExceptionNotPositiveDimension& _exception);
  ExceptionNotPositiveDimension(int _line, const char *_file);
  ~ExceptionNotPositiveDimension();
};

class ExceptionDifferentDimensions : public MyException
{
public:
  ExceptionDifferentDimensions();
  ExceptionDifferentDimensions(const ExceptionDifferentDimensions& _exception);
  ExceptionDifferentDimensions(int _line, const char *_file);
  ~ExceptionDifferentDimensions();
};

#endif // !__MY_EXCEPTIONS_H__