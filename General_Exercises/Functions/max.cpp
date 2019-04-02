// Write a program with associated function so it asks user for 2 numbers and then prints the maximum value from these 2 numbers?

#include <iostream>
using namespace std;

float massimo(float x, float y)
{
  return (x>y) ? x : y;
}


int main() {

  cout << "Hello World!\n";

  float num1, num2;
  
  cout << "Please enter a number: ";
  cin >> num1;

  cout << "Please enter your second number: ";
  cin >> num2;

  printf("The highest number inserted was: %f\n", massimo(num1, num2));

  return 0;
}
