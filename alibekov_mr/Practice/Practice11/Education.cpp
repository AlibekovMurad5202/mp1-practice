#include "Education.h"

Education::Education()
{
  school = unknown;
  number_of_class = 0;
  university = unknown;
  grade = 0;
  other = unknown;
}

Education::~Education()
{
}

Education::Education(const Education & _ed)
{
  school = _ed.school;
  number_of_class = _ed.number_of_class;
  university = _ed.university;
  grade = _ed.grade;
  graduationDate = _ed.graduationDate;
  universityGraduationDate = _ed.universityGraduationDate;
  other = _ed.other;
}

const Education & Education::operator=(const Education & _ed)
{
  if (this == &_ed)
    return *this;
  school = _ed.school;
  number_of_class = _ed.number_of_class;
  university = _ed.university;
  grade = _ed.grade;
  graduationDate = _ed.graduationDate;
  universityGraduationDate = _ed.universityGraduationDate;
  other = _ed.other;
  return *this;
}

bool Education::operator==(const Education & _ed) const
{
  return (school == _ed.school)
      && (number_of_class == _ed.number_of_class)
      && (university == _ed.university)
      && (grade == _ed.grade)
      && (graduationDate == _ed.graduationDate)
      && (universityGraduationDate == _ed.universityGraduationDate)
      && (other == _ed.other);
}
