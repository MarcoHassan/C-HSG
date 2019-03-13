/*
The below function should swap the numbers by using pointers...end result should be
Before swapping
a = 1
b = 2

After swapping
a = 2
b = 1

However, there are 3 mistakes in the program - find and fix them.

*/

#include <iostream>
using namespace std;

// Function prototype
void swap(int&, int&);

int main()
{
    int a = 1, b = 2;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a, b);

    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

// Function definition
void swap(int& n1, int& n2) {
    int temp;
    temp = (*&n1);
    n1 = (*&n2);
    n2 = temp;
}
