#ifndef NODE_H
#define NODE_H

#include "student.h"

using namespace std;

//node class
class Node{
    public:
      Node(Student*); //constructor
      ~Node(); //destructor
      //setters
      void setStudent(Student* newStudent);
      void setNext(Node* newNext);
      //getters
      Student* getStudent();
      Node* getNext();
    private:
      //variables
      Student* student;
      Node* next;
};
#endif