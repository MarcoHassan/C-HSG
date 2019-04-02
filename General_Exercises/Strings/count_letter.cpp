// Find Frequency of Characters of a String Object

// Your task is to define a new string named mystring and assign to it "C++ Programming is awesome"

// once you do that, you will have to count the number of characters of letters a and i

// at the end you will print the number of occurences

#include <iostream>
using namespace std;

int main()
{
  const char * mystring = "C++ Programming is awesome"; // you define a C-string that ends with "\0"

  int count = 0;
  int i = 0;

  while(mystring[i] != '\0')
      {
	if( mystring[i] == 'a' || mystring[i] == 'i')
	  {
	  count += 1;
	  }
	i++;
       };

  printf("%d\n", count);
  return 0;
}


