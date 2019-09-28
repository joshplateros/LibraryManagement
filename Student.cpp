#include <iostream>
#include <string>
#include <map>

#include "Student.h"

void Student::addStudent(const std::string & name, const int & id)
{
    Student *newPtr = new Student();
    newPtr->setStudentName(name);
    newPtr->setStudentId(id);
}
