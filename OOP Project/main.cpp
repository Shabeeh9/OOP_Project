#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "System.h"
#include "Student.h"
#include "Course.h"
#include "Validator.h"
#include "FileHandler.h"


int main() {
    System learningManagementSystem;
    learningManagementSystem.loadDataFromFiles();
    learningManagementSystem.displayMainMenu();
   
    return 0;
}
