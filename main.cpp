/******************************************************************************

Linked List Part 2 by Nabhan Abedin
Did not get my partner's nodes so I used my own
4.13.2021

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip> //for setprecision
#include "node.h"
#include "student.h"

using namespace std;

//function prototypes
void addStudent(Node* previous, Student* student);
void printStudent(Node* next);
void deleteStudent(Node* next, Node* previous, char name[]);
float averageGpa(Node* next);

Node* first = NULL;

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2); //for showing gpa average to 2 decimal places 
    bool running = true;
    while(running) {
        char command[20];
        cout <<"Enter command (ADD, PRINT, DELETE, AVERAGE, QUIT): ";
        cin >> command;
        for (int i = 0; i < sizeof(command); i++) { //convert command to uppercase
            command[i] = toupper(command[i]);
        }
        //call functions dependent on command
        if (strcmp(command, "ADD") == 0) {
            Student* student = new Student;
            cin.ignore(100, '\n');
            cout << endl << "What is the student's first name?" << endl;
            cin.get(student -> getFirst(), 20);
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "What is the student's last name?" << endl;
            cin.get(student -> getLast(), 20);
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "What is the student's id #?" << endl;
            cin >> *student -> getId();
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "What is the student's gpa?" << endl;
            cin >> *student -> getGpa();
            cin.clear();
            cin.ignore(100, '\n');
            addStudent(first, student);
        } else if (strcmp(command, "PRINT") == 0) {
            if (first == NULL) {
                cout << "There are not students in the list." << endl;
            } else {
                cout << endl;
                printStudent(first);
            }
        } else if (strcmp(command, "DELETE") == 0) {
            char name[20];
            if (first == NULL) {
                cout << "There are no students in the list." << endl;
            } else {
                cout << "What is the first name of the student you want to delete?" << endl;
                cin >> name;
                cin.clear();
                cin.ignore(100, '\n');
                deleteStudent(first, NULL, name);
            }
        } else if (strcmp(command, "AVERAGE") == 0) {
            if (first == NULL) {
                cout << "There are no students in the list." << endl;
            } else {
                cout << "Average GPA: " << averageGpa(first) << endl;
            }
        } else if (strcmp(command, "QUIT") == 0) {
            cout << "Program has ended. ";
            running = false; //exit program
        }
    }
    return 0;
}

void addStudent(Node* previous, Student* student) {
    if (first == NULL) { //if studentlist is empty, make new student
        first = new Node(student);
    } else if (student -> getId() < first -> getStudent() -> getId()) { //reorder students based on id number (least to greatest)
        Node * temp = new Node(first -> getStudent());
        temp -> setNext(first -> getNext());
        first -> setStudent(student);
        first -> setNext(temp);
    } else if (previous -> getNext() == NULL) { //add new student
        Node* newNode = new Node(student);
        previous -> setNext(newNode);
    } else if (student -> getId() < previous -> getNext() -> getStudent() -> getId()) { //set position of new student based on id number
        Node* newNode = new Node(student);
        newNode -> setNext(previous -> getNext());
        previous -> setNext(newNode);
    } else {
        addStudent(previous -> getNext(), student); //recursive function to maintain node positions
    }
}

void printStudent(Node* next) {
    if (next != NULL) { 
        //print student stats
        cout << next -> getStudent() -> getLast() << ", ";
        cout << next -> getStudent() -> getFirst() << endl;
        cout << *next -> getStudent() -> getId() << endl;
        cout << *next -> getStudent() -> getGpa() << endl << endl;
        //recursion to print next student
        printStudent(next -> getNext());
    }
}

void deleteStudent(Node* next, Node* previous, char name[]) { //remove student from list via node destructors
  char yesno;
  if (next == first && strcmp(next -> getStudent() -> getFirst(), name) == 0) {
    cout << endl << next -> getStudent() -> getLast() << ", ";
    cout << next -> getStudent() -> getFirst() << endl;
    cout << *next -> getStudent() -> getId() << endl;
    cout << *next -> getStudent() -> getGpa() << endl << endl;
    cout << "Would you would like to delete this student? (y/n)" << endl << ">> ";
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (yesno == 'y') {
      cout << "Student has now been deleted" << endl << endl;
      if (next -> getNext() == NULL) {
	next -> ~Node();
	first = NULL;
      }
      else {
	first = next -> getNext();
	next -> ~Node();
	deleteStudent(first, NULL, name);
      }
    }
    else if (yesno == 'n') {
      cout << "Student will not be deleted" << endl << endl;
      if (next -> getNext() != NULL) {
	deleteStudent(next -> getNext(), next, name);
      }
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
  else if (strcmp(next -> getStudent() -> getFirst(), name) == 0) {
    cout << endl << next -> getStudent() -> getLast() << ", ";
    cout << next -> getStudent() -> getFirst() << endl;
    cout << next -> getStudent() -> getId() << endl;
    cout << next -> getStudent() -> getGpa() << endl << endl;
    cout << "Would you would like to delete this student? y/n" << endl << ">> ";
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (yesno == 'y') {
      cout << "Student has now been deleted" << endl << endl;
      previous -> setNext(next -> getNext());
      next -> ~Node();
    }
    else if (yesno == 'n') {
      cout << "Student will not be deleted" << endl << endl;
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
  if (next -> getNext() != NULL) {
    deleteStudent(next -> getNext(), next, name);
  }
}

float averageGpa(Node* next) { //average gpa's
    float total = 0;
    int counter = 0;
    if (next == first) {
        total += *next -> getStudent() -> getGpa();
        counter++;
    }
    while (next -> getNext() != NULL) {
        total += *next -> getNext() -> getStudent() -> getGpa();
        counter++;
        next = next -> getNext();
    }
    return (total/counter);
}
