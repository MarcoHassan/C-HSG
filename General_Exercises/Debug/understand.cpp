// In this task you do not need to paste any code, but just an explanation why in 'int&' the sign & is used
// so just provide an explanation why & is used and what that means exactly

/* In the program below we make use of PASSING BY REFERENCE. This means that we are actually passing the position of the pointer a. In such a way the program below will save the assignments in the heap and not in the stack so that even after the function is executed the changes to the variables will affect the subsequent evaluations. 

In simple words the "&" operator in this case will pass the the memory address reserved to the variable and the results will be persistent and directly stored in the address specified.*/

#include <iostream>
using namespace std;

void duplicate (int& a, int& b, int& c)
{
  a*=2;
  b*=2;
  c*=2;
}

int main ()
{
  int x=1, y=3, z=7;
  duplicate (x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  return 0;
}
