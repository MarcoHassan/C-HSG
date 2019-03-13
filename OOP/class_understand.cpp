/*
Go through the below code and explain in few lines of text what you understood from the code - what is the name of the technique used in C++ 

*/

#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout  << "Default constructor of base class called" << endl;
	}
	Person(string lName, int year)
	{
		cout  << "Parameterized constructor of base class called" << endl;
		lastName = lName;
		yearOfBirth = year;
	}
	string lastName;
	int yearOfBirth;
};

//derived class
class Student :public Person
{
public:
	Student()
	{
		cout  << "Default constructor of Derived class called" << endl;
	}
	Student(string lName, int year, string univer)
	{
		cout  << "Parameterized constructor of Derived class called" << endl;
		university  = univer;
	}
	string university;
};

int main ()
{
Student student1; //Using default constructor of Student class
Student student2("John", 1990, "London School of  Economics"); //calling parameterized constructor of Student class
	return 0;
}
