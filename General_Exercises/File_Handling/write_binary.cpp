// Can you write a program which write bytes into the file test.dat, so it writes your name in the file and then reads your name that is then displayed?

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  std::cout << "Hello World!\n";

  // Open the file with the binary flag
  // The ofstream class provides a member function named write that allows for information to be written in binary form to the stream.
  ofstream outFile;

  outFile.open("test.dat", ios::out | ios::binary);

  // Define variable to be written
  char name[30] = "Marco";

  // Write to the file binary data
  outFile.write((char *) &name, sizeof(name)); // notice the casting.

  // Free up resources
  outFile.close();

  // Read the binary file
  ifstream inFile;

  inFile.open("test.dat", ios::in | ios::binary);

  // Specify helper variable
  string read;

  if(inFile.is_open())
  {
    while (!inFile.eof()) // continue till there are no more lines
     {
       getline(inFile, read);
       cout << read;
     }

    cout << endl;
   
    inFile.close();

  }
  else cout << "Unable to open file";

  return 0;
}


// Good source: http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/cppBinaryFileIO-2.html
