
#include "FileHandler.h"
#include "Student.h" // Include Student header file
#include "Course.h"  // Include Course header file

Student** FileHandler::readStudentFromFile(string filename, Course** courses)
{
    ifstream fin(filename);
    fin >> Student::totalStudents;
    fin.ignore();
    fin.ignore();
    
    int size = Student::totalStudents;
    Student** students = new Student*[size];
    
    int count = 0;
    while(count < size)
    {
        string name, rollNo, contact, fileCourses;
        int age, regCourses;
        getline(fin, name);
        getline(fin, rollNo);
        fin >> age;
        fin.ignore();
        getline(fin, contact);
        fin >> regCourses;
        fin.ignore();
        getline(fin, fileCourses);
         
        
        students[count] = new Student(name, rollNo, age, contact, regCourses);
        cout << students[count]->name << endl;
        // Assigning the registered courses to student
        int prevIndex = 0;
        for (int i = 0; i < regCourses; i++)
        {
            int nextIndex;
            if (fileCourses.find(",", prevIndex) != string::npos)
                nextIndex = fileCourses.find(",", prevIndex);
            else
                nextIndex = fileCourses.length();
            
            string course = fileCourses.substr(prevIndex, nextIndex); //slicing the string from comma
            
            for (int j = 0; j < Course::totalCourses; j++) // loop to find the registered course
            {
                if (course == courses[j]->code) // Aggregation when the course is found
                {
                    students[count]->courses[i] = courses[j]; // pointing the student to the course
                    
                    // pointing the course to student
                    if (courses[j]->regStudents > 0)
                    {
                        Student** temp = new Student*[courses[j]->regStudents];
                        
                        // expanding the array by first copying, deleting and increasing the size
                        for (int k = 0; k < courses[j]->regStudents; k++)
                        {
                            temp[k] = courses[j]->students[k];
                        }
                        courses[j]->students = NULL;
                        students = new Student*[courses[j]->regStudents + 1];
                        
                        
                        for (int k = 0; k < courses[j]->regStudents; k++)
                        {
                            courses[j]->students[k] =  temp[k];
                        }
                        cout << students[count]->name << endl;
                    }
                    else{
                        courses[j]->students = new Student*[1];
                    }
                    
                    courses[j]->students[courses[j]->regStudents] = students[count];
                    courses[j]->regStudents++;
                }
            }
            prevIndex = nextIndex + 1;
        }
        
        count++;
        fin.ignore();
    }
    return students;
}

Course** FileHandler::readCoursesFromFile(string filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "File not Open\n";
    }
    fin >> Course::totalCourses;
    fin.ignore();
    fin.ignore();
    
    int size = Course::totalCourses;
    Course** courses = new Course*[size];
    
    int count = 0;
    while(count < size)
    {
        string courseCode, courseName, courseInst;
        int credHrs, cap;
        getline(fin, courseCode);
        getline(fin, courseName);
        getline(fin, courseInst);
        fin >> credHrs;
        fin >> cap;
        
        courses[count] = new Course(courseCode, courseName, courseInst, credHrs, cap);
        
        count++;
        fin.ignore();
    }
    
    
    
    
    return courses;
}
