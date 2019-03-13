// Create a program that creates an array of five floating-point values, then prints out just the second value. 

#include <iostream>

float n[4] = {};

int main() {

  std::cout << "Hello World!\n";
  
  for( int i = 0; i<5; i++)
    {
      std::cout << "print me!\n";
      std::cin >> n[i];
    };

  printf("Array Element [1]: %f\n", n[1]);

  
  return 0;
}
