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
  MyException() { str_what = 0; line = 0; file = 0; };
  MyException(int _line, const char *_file) { str_what = 0; line = _line; file = _file; };
  MyException(const char* message, int _line, const char *_file) 
        : str_what(message), line(_line), file(_file) {};
  ~MyException() { line = -1; }

  virtual const char* what() const { return str_what ? str_what : s;  }
  virtual int errorLine() const { return line; }
  virtual const char* errorFile() const { return file; }
};

class ExceptionOutOfRange : public MyException 
{
public:
  ExceptionOutOfRange() { str_what = "Index out of bounds!"; line = -1; file = 0; }
  
  ExceptionOutOfRange(int _line, const char *_file) { \
    str_what = "Index out of bounds!"; line = _line; file = _file; }
  
  ~ExceptionOutOfRange() { line = -1; }
};

class ExceptionDifferentDimensions : public MyException
{
public:
  ExceptionDifferentDimensions() {  \
    str_what = "Vectors have different dimensions!"; line = -1; file = 0; }

  ExceptionDifferentDimensions(int _line, const char *_file) {  \
    str_what = "Vectors have different dimensions!"; line = _line; file = _file; }
  
  ~ExceptionDifferentDimensions() { line = -1; }
};

class ExceptionBadAlloc : public MyException
{
public:
  ExceptionBadAlloc() { str_what = "Bad memory allocation!"; line = -1; file = 0; }

  ExceptionBadAlloc(int _line, const char *_file) {  \
      str_what = "Bad memory allocation!"; line = _line; file = _file; }

  ~ExceptionBadAlloc() { line = -1; }
};

#endif // !__MY_EXCEPTIONS_H__