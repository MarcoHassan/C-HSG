/*
Write a c++ class called 'student' with

Data members:

name(char type),

marks1,marks2 (integer type)
The program asks the user to enter name and marks. Then calc_media() calculates the media note and disp() display name and total media mark on screen in different lines.


*/

#include <iostream>
#include <string>
using namespace std;

class Student
{

  // set as private to respect confidenciality.
  int marks1, marks2;

  public:
    string name;
    float calc_media(int, int);
    void disp(Student);

    // Make use of constructor to initialize the object
    Student(string, int, int);

};

int main() {

   string nam;int m1,m2;

   cout << "Enter name: ";
   cin>> nam;
   cout << "Enter marks of two subjects separated by a whitespace: ";
   cin>> m1;
   cin>> m2;

   Student student1(nam,m1,m2);
   student1.disp(student1);

   return 0;
}

/////////////////
// Constructor //
/////////////////

Student::Student(string nome, int grade1, int grade2)
{
  name = nome;
  marks1 = grade1;
  marks2 = grade2;

  cout << "\nInstance of Object Student was constructed.\n";
}


/////////////////////////////////
// Member Function Declaration //
/////////////////////////////////

float Student::calc_media(int x, int y)
{
  return ((float)(x+y))/2; // notice the float in order to assure that the casting is correct.
}

void Student::disp(Student s)
{
  cout << "Student Name: " << s.name << endl;

  cout << "Student Average: " << s.calc_media(s.marks1, s.marks2) << endl;
}
