#include "Student.h"

int Student::totalStudents = 0;

Student::Student(string n, string r, int a, string c, int rC)
{
    name = n;
    roll_num = r;
    age = a;
    contact = c;
    courses = nullptr;
    
    registeredCourses = rC;
    courses = new Course*[rC];
}


string Student::getRollNum()
{
    return roll_num;
}


void Student::setName(string str)
{
    name = str;
}
void Student::setRollNum(string rollNum)
{
    roll_num = rollNum;
}
void Student::setAge(int a)
{
    age = a;
}
void Student::setContact(string str)
{
    contact = str;
}
void Student::setRegisteredCourses(int rC)
{
    registeredCourses = rC;
}
void Student::addCourse(Course* course)
{
    if(registeredCourses > 0)
    {
        Course** temp = new Course*[registeredCourses];
            
            // expanding the array by first copying, deleting and increasing the size
        for (int i = 0; i < registeredCourses; i++)
        {
            temp[i] = courses[i];
        }
        courses = NULL;
        courses = new Course*[registeredCourses + 1];
            
            
        for (int i = 0; i < registeredCourses; i++)
        {
           courses[i] =  temp[i];
        }
    }
    else{
        courses = new Course*[1];
    }
    
    courses[registeredCourses] = course;
    registeredCourses++;
}
