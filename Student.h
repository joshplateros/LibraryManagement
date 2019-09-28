#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <map>


class Student
{
    public:
    Student();

    void addStudent(const std::string & name, const int & id);
    
    void setStudentName(const std::string & name);
    void setStudentId(const int & Id);
    std::string getName();



    private:
    int m_id;
    std::string name;




};







#endif 
