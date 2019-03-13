// Write a program that will write 3 sentences in the file fruits.txt that will then be read and printed line by line.

// example: sentence#1: This is an example1, sentence #2: This is an example2 and sentence #3: This is an example3

// Write a program where you ask the user to provide his/her name, then you write his/her name in the file.
// Finally you read the file and print its content.
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
fstream myfile;

int main() {
  
  cout << "Hello World!" << endl;

  try
  {
      fileCreation(myfile);

      writeToFile(myfile);

      readFromFile(myfile);

      // To free up resources and avoid memory leaks.
      myfile.close();      
  }

  // And in case of error.
  catch (...)//catch all exceptions
  {
    myfile.close();
  }
  
  return 0;
}

//////////////////////////
// Function Declaration //
//////////////////////////

void fileCreation(fstream& file)
{
  //helper variable
  char file_format[] = ".txt";
  char name[200];

  cout << "Enter the name of the txt to be create in the current working directory: ";
    
  std::cin >> name;

  strcat(name, file_format);

  //Specify the file that will be used for writing.
  // fstream::out to create the file in case it doesn't exist.
  file.open(name, fstream::out);
  
}


void writeToFile(fstream& file)
{
  // Helper variable
  char reply[50];

  cout << "What is your name? ";

  cin >> reply;

  file << "My name is " << reply << endl;

}

void readFromFile(fstream& file)
{
  // Create necessary helper variables
  char input[200];

  // Set the marker at the beginning in order to read the file from the beginning.				     
  file.seekg(ios::beg);
				     
  //extract first line into str
  file >> input;
  cout << input << endl;
}
