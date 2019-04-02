/*
Go through the below code and explain in few lines of text what you understood from the code - what is the name of the technique used in C++ 

*/

#include <iostream>
using namespace std;

class Person // define an object person.
{
public: 
        Person() /* constructor to initialize the the object and assign 
		    the necessary memory space to it. */
	{
		cout  << "Default constructor of base class called" << endl;
	} // feedback message above.
  
	Person(string lName, int year) /* constructor already initializing
					  the object length and 
					  yearOfBirth */
	{
	  cout  << "Parameterized constructor of base class called";
	  cout << endl;
	  lastName = lName;
	  yearOfBirth = year;
	}

        // Specifying public member variables
        string lastName;
	int yearOfBirth;
};

//derived class
class Student :public Person
{
public:
        // specify base constructor for Student objects. 
	Student()
	{
		cout  << "Default constructor of Derived class called" << endl;
	}

        // Specify parameterized constructor for Student objects. 
	Student(string lName, int year, string univer)
	//:Person(lName, year) // my addition to initialize the last Name and year based on the base constructor.
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
       // C++ recognizes which one your are calling based  on the overloading principle similar to the one of function declaration.

       // This final line is my test. At the current stage the lName and year variables are not initialized. In order to change that you have to remove the commentary from the Subclass constructor above where the base constructor is referred.
       cout<<  student2.lastName <<endl;
       return 0;
}
