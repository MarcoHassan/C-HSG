// Write a program that uses a loop which runs 100 times ( you can use while(true) ).

//  Each time the loop runs, it says Enter a number and wait for some input.
// program should do the sum of all entered numbers
// Try running the program, and type in different things. 
// Write the program so the program breaks when a negative number is entered


#include <iostream>
using namespace std;

int main() {
  std::cout << "Hello World!\n";

  // Create an array ot save the result
  float array[99] = {};
  
  int i = 0;

  float sum = 0;  
  
  while(i<100)
    {
      cout << "Enter a number:\n";

      float help;
      
      cin >> help;

      if(help < 0)
	{
	  break;
	}

	array[i] = help;

	sum += array[i];
	
       i++;
    }

  printf("The sum of the entered positive numbers is: %f\n", sum);

  return 0;
}
