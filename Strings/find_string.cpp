// 1st intialize a variable called fruit and set it to "Fruit named lemon is tasty."

// Write a program that checks if lemon exists in the fruit string - if yes, program says 'I found it', if not 'I did not find it'.
// Check the same for 'orange'

#include <iostream>
#include <string>
using namespace std;

int main() {

  std::cout << "Hello World!\n";
  
  string fruit = "Fruit named lemon is tasty";

  int find = fruit.find("lemon");

  if( find == -1)
    {
      printf("I did not find it\n");
    }

  else
    {
      printf("I found it\n");
    }
}
