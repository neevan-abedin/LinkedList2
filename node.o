#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//constructors
Node::Node(Student* nextStudent) {
    student = nextStudent;
    next = NULL;
}

//destructor
Node::~Node() {
    delete &student;
    next = NULL;
}

//setters
void Node::setStudent(Student* nextStudent) {
    student = nextStudent;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}

//getters
Student* Node::getStudent() {
    return student;
}

Node* Node::getNext() {
    return next;
}