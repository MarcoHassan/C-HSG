// Modify the following program by adding a condition which will stop the loop and print the sum once the sum is higher than 20

#include <iostream>
using namespace std;

int main() 
{
    float number, sum = 0.0;
    
    do {
        cout<<"Enter a number: ";
        cin>>number;
        sum += number;
    }
    while(sum < 20.0);

    cout<< "Total sum = "<< sum << endl;
    
    return 0;
}
