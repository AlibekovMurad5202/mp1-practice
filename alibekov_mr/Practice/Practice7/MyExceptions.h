#ifndef __MY_EXCEPTIONS_H__
#define __MY_EXCEPTIONS_H__

class MyException
{
protected: 
  char s[20] = "Unknown exception!";
  const char* str_what;
  int line;
  const char* file;

public:
  MyException();
  MyException(int _line, const char *_file);
  MyException(const MyException& _exception);
  MyException(const char* message, int _line, const char *_file);
  ~MyException();

  virtual const char* what() const { return str_what ? str_what : s;  }
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

class ExceptionDifferentDimensions : public MyException
{
public:
  ExceptionDifferentDimensions();
  ExceptionDifferentDimensions(const ExceptionDifferentDimensions& _exception);
  ExceptionDifferentDimensions(int _line, const char *_file);
  ~ExceptionDifferentDimensions();
};

class ExceptionBadAlloc : public MyException
{
public:
  ExceptionBadAlloc();
  ExceptionBadAlloc(const ExceptionBadAlloc& _exception);
  ExceptionBadAlloc(int _line, const char *_file);
  ~ExceptionBadAlloc();
};

class ExceptionEmptyVector : public MyException
{
public:
  ExceptionEmptyVector();
  ExceptionEmptyVector(const ExceptionEmptyVector& _exception);
  ExceptionEmptyVector(int _line, const char *_file);
  ~ExceptionEmptyVector();
};

class ExceptionNotPositiveDimension : public MyException
{
public:
  ExceptionNotPositiveDimension();
  ExceptionNotPositiveDimension(const ExceptionNotPositiveDimension& _exception);
  ExceptionNotPositiveDimension(int _line, const char *_file);
  ~ExceptionNotPositiveDimension();
};

#endif // !__MY_EXCEPTIONS_H__