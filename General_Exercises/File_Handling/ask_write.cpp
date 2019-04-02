// Write a program where you ask the user to provide his/her name, then you write his/her name in the file.

// Finally you read the file and print its content.

// Libraries
#include <iostream>
#include <fstream> // to manage files in c++ environment.
#include <cstring> // to concatenate the c-strings.
#include <string>
using namespace std;

// Define global variable
static char name[200];

//////////////////////////
// Functions Definition //
//////////////////////////

/* Remember to pass fstream by reference as it cannot be copied */
void myFileCreation (fstream&);
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
      myFileCreation(myfile);
      cout << "File connection were successfully established.\n";

      // Ask and write the name to myfile.
      writeToFile(myfile);
      
      // Read name from myfile.
      readFromFile(myfile);


      // To free up resources and avoid memory leaks.
      myfile.close();
      cout << "Your name was correctly written in the text file and the cinnection with the latter was closed to avoid memory leaks.\n";
}

  // And in case of error assure to free up resources.
  catch (...)//catch all exceptions
  {
    if(myfile.is_open())
      {
	myfile.close();
	cout << "An error occured and the file connession was closed.\n";
      }
  }
  
  return 0;
}

//////////////////////////
// Function Declaration //
//////////////////////////

void myFileCreation(fstream& file)
{
  //helper variable
  char file_format[] = ".txt";

  cout << "Enter the name of the txt to be create in the current working directory: ";
    
  std::cin >> name;

  strcat(name, file_format);

  //Specify the file that will be used for writing and reading.
  file.open(name, ios::out);
  
}


void writeToFile(fstream& file)
{
  // Helper variable
  char reply[50];

  cout << "What is your name? ";

  cin >> reply;

  file << "My name is " << reply << "\n";

}

void readFromFile(fstream& file)
{
  // Open connection in read mode
  file.close();
  file.open(name, ios::in);
  // Create necessary helper variables
  string input;

  // Set the marker at the beginning in order to read the file from the beginning.
  file.seekg(ios::beg);

  while(getline(file, input))
    {
      cout << input << endl;
    }
}
