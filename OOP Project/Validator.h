//
//  Validator.h
//  OOP Project
//
//  Created by Shabeeh Abbas on 12/12/2023.
//

#ifndef Validator_h
#define Validator_h

#include <iostream>
#include <string>

class Validator {
private:
    std::string input;
    std::string type;
    std::string constraints;

public:
    Validator(std::string input, std::string type, std::string constraints);
    // Add methods to validate the input according to the type and constraints
};

#endif /* Validator_h */
