/*
Write a c++ class called 'student' with

Data members:

name(char type),

marks1,marks2 (integer type)
The program asks the user to enter name and marks. Then calc_media() calculates the media note and disp() display name and total media mark on screen in different lines.


*/


#include <iostream>
using namespace std;

class Student{

	public:
	

};

int main() {
  char* nam;int m1,m2;

	cout << "Enter name:";
	cin>> nam;
	cout << "Enter marks of two subjects:";
	cin>> m1;
	cin>> m2;
	Student student1(nam,m1,m2);
	student1.disp();

	return 0;
}
