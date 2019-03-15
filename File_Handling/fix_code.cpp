// Write a program that will write 3 sentences in the file fruits.txt that will then be read and printed line by line.

// example: sentence#1: This is an example1, sentence #2: This is an example2 and sentence #3: This is an example3

#include <iostream>
#include <fstream> // to manage files in c++ environment.
#include <cstring> // to concatenate the c-strings.
using namespace std;

//////////////////////////
// Functions Definition //
//////////////////////////

/* Remember to pass fstream by reference as it cannot be copied */
void fileCreation (fstream&);
void writeToFile (fstream&);
void readFromFile (fstream&);

////////////////////
// Code Execution //
////////////////////

// Open the connection with a generic file.
fstream fruit;

int main() {
  
  cout << "Hello World!" << endl;

  try
  {
      // Open fruit connection
      fruit.open("fruit.txt", ios::out);

      // Write to the fruit file.
      fruit << "Bananas are sweet\n" << "Apple are sour\n" << "Orange are juicy\n";
            
      // Read form fruit file.
      fruit.close();
      fruit.open("fruit.txt", ios::in);      

      string readin; // helper string.
      
      while(getline(fruit, readin))
	{
	  cout << readin << endl;
	}      

      // To free up resources and avoid memory leaks.
      fruit.close();
      cout << "The connection with the fruit file was closed to avoid memory leaks.\n";
  }

  // To free up resources and avoid memory leaks.
  catch (...)//catch all exceptions
  {
    if(fruit.is_open())
      {
	fruit.close();
      }    
  }
  
  return 0;
}
