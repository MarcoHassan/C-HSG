// Write a program that uses 'for' loop to print 15 times the following line
// 'This is line number 1'
// 'This is line number 2'...till 15


#include <iostream>

int main() {
  std::cout << "Hello World!\n";

  for (int i = 0; i<15; i++)
    {
      printf("This is line number: %d\n", (i+1));
    }

  return 0;
}
