#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

//student class
class Student{
    public:
      Student(); //constructor
      ~Student(); //destructor
      //getters
      char* getFirst();
      char* getLast();
      int* getId();
      float* getGpa();
    private:
      //stats
      char firstName[20];
      char lastName[20];
      int id;
      float gpa;
};
#endif