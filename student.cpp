#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){
    //constructor
}

//destructor
Student::~Student() {
    delete &firstName;
    delete &lastName;
    delete &id;
    delete &gpa;
}

//getters
char* Student::getFirst() {
    return firstName;
}

char* Student::getLast() {
    return lastName;
}

int* Student::getId() {
    return &id;
}

float* Student::getGpa() {
    return &gpa;
}