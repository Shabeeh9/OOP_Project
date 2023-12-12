//
//  System.cpp
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#include "System.h"
#include "FileHandler.h"


void System::displayMainMenu() {
    int option;
    do {
        std::cout << "Main Menu\n\n";
        std::cout << "1- Enroll a student\n";
        std::cout << "2- Course Registration\n";
        std::cout << "3- Attendance\n";
        std::cout << "4- Marks\n";
        std::cout << "5- Course Withdraw\n";
        std::cout << "6- Exit\n";
        std::cout << "Press 1 to 6 to select an option: ";

        std::cin >> option;

        switch (option) {
            case 1:
                displayEnrollStudentMenu();
                break;
            case 2:
                //displayCourseRegistrationMenu();
                break;
            case 3:
                //displayAttendanceMenu();
                break;
            case 4:
                //displayMarksMenu();
                break;
            case 5:
                //displayCourseWithdrawMenu();
                break;
            case 6:
                std::cout << "Exiting...\n";
                
                break;
            default:
                std::cout << "Invalid option. Please select again.\n";
                break;
        }
    } while (option != 6);
}

void System::displayEnrollStudentMenu() {
    int option;
    do {
        std::cout << "\nEnroll a Student\n\n";
        std::cout << "1- Display already enrolled students\n";
        std::cout << "2- Add a student\n";
        std::cout << "3- Remove a student\n";
        std::cout << "4- Edit student details\n";
        std::cout << "5- Back\n";
        std::cout << "Press 1 to 5 to select an option: ";

        std::cin >> option;

        switch (option) {
            case 1:
                displayAllEnrolledStudents();
                break;
            case 2:
                enrollStudent();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                //editStudent();
                break;
            case 5:
                std::cout << "Going back to the main menu...\n";
                return; // Return to the main menu
            default:
                std::cout << "Invalid option. Please select again.\n";
                break;
        }
    } while (option != 5);
}



void System::displayAllEnrolledStudents() {
    std::cout << "\nList of Enrolled Students\n";

    // Loop through the 'students' vector and display student details
    for (int i = 0; i < Student::totalStudents; i++) {
        std::cout << "Name: " << students[i]->getName() << std::endl;
        std::cout << "Roll Number: " << students[i]->getRollNumber() << std::endl;
        std::cout << "Age: " << students[i]->getAge() << std::endl;
        std::cout << "Contact: " << students[i]->getContact() << std::endl;

//        // Display enrolled courses
//        std::cout << "Enrolled Courses:\n";
//        const std::vector<std::string>& courses = student.getCourses();
//        for (const auto& course : courses) {
//            std::cout << " - " << course << std::endl;
//        }

        std::cout << "-----------------\n";
    }
}

void System::loadDataFromFiles()
{
    string filename = "courses.txt";
    courses = FileHandler::readCoursesFromFile(filename);
    filename = "students.txt";
    students = FileHandler::readStudentFromFile(filename, courses);
    cout << "less go";
}

void System::enrollStudent()
{
    if(true)
    {
        string name, rollNo, contact;
        int age, registeredCourses;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact Number: ";
        cin >> contact;
        cout << "Enter Number of Registered Courses: ";
        cin >> registeredCourses;
        
        Student* student = new Student(name, rollNo, age, contact, registeredCourses);
        
        //for (int i = 0; i < )
        
        // Aggregation is needed right now
        // validation is also needed
    }
}
void System::removeStudent()
{
    string rollNo;
    cout << "Enter Roll Numnber of Student(22L-6666): ";
    cin >> rollNo;
    
    // validate here
    if(true)
    {
        int index;
        for (int i = 0; i < Student::totalStudents; i++)
        {
            if (rollNo ==  students[i]->getRollNum())
                index = i;
        }
        Student* temp = students[index];
        for (int i = index; i < Student::totalStudents - 1; i++)
            students[i] = students[i + 1];
        
        
        
        // need to remove from courses as well
        delete temp;
        
        cout << "Student Removed Successfully\n";
    }
    
}
void System::editStudent()
{
    
}

void System::registerCourse()
{
    
    string rollNo;
    cout << "Enter Roll Numnber of Student(22L-6666): ";
    cin >> rollNo;
    
    // validation of rollNo needed
    if(true)
    {
        int index;
        for (int i = 0; i < Student::totalStudents; i++)
        {
            if (rollNo ==  students[i]->getRollNum())
                index = i;
        }
        
        string course;
        cout << "Enter Code of Course: ";
        cin >> course;
        for (int i = 0; i < Course::totalCourses; i++)
        {
            if (course == courses[i]->getCode()) // Aggregation when the course is found
            {
                students[index]->addCourse(courses[i]); // pointing the student to the course
                courses[i]->addStudent(students[index]);
            }
        }
        cout << "Student Registered Successfully\n";
    }
}
