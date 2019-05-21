#ifndef __EDUCATION_H__
#define __EDUCATION_H__

#include "Date.h"

const std::string unknown = "UNKNOWN";

class Education
{
public:
  std::string school;
  UINT number_of_class;
  std::string university;
  UINT grade;
  Date graduationDate;
  Date universityGraduationDate;
  std::string other;

  Education();
  ~Education();
  Education(const Education& _ed);
  
  const Education& operator= (const Education& _ed);
  bool operator== (const Education& _ed) const;
};

#endif