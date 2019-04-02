// Write a function that divides two numbers (provided as parameters). 

#include <iostream>
#include <stdlib.h> // to parse the command line inputs and tead them as floaters.

float devide(float x, float y)
{
  return x/y;
}

/* to specify the numbers of the devision in the shell whe calling the
   program use argc and argv inputs */
int main(int argc, char** argv) {
  std::cout << "Hello World!\n";

  printf("%f\n", devide(atof(argv[1]),atof(argv[2])));

  return 0;

}

/* Usage: when running the program, for instance calling ./<name of the program> you have to specify the two inputs elements.

For instance to run the program run: 
          ./<name of the program> <first division argument> <second division argument>
