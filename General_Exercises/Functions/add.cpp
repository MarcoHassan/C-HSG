// Write  a function that adds two numbers, returns the result and you print it in the main program

#include <iostream>

float addition(float x, float y)
{
  return x+y;
}

int main() {

  float num1, num2;
  
  std::cout << "Hello World!\n";

  std::cout << "Please enter one number: ";

  std::cin >> num1;

  std::cout << "Please enter a second number: ";

  std::cin >> num2;

  printf("The sum of the inserted numbers is: %f\n", addition(num1, num2));

  return 0;
}
