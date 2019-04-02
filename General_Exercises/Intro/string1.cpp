// Your program has to do the following: Read a string "This is my string and I like it", then return a substring from the position number 11 and then return the substring "I like it"

#include <iostream>
#include <string>
using namespace std;

int main() {

  std::cout << "Hello World!\n";
  
  string mystring = "This is my string and I like it";

  int i = 11;

  while(mystring[i] != '\0')
    {
      cout << mystring[i];
      i++;
    };

  cout << endl;

  int j = mystring.find("I");

  while(mystring[j] != '\0')
    {
      cout << mystring[j];
      j++;
    };

  cout << endl;
    
  return 0;
}
