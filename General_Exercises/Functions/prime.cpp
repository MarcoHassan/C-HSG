#include <iostream>
using namespace std;

int checkPrimeNumber(int number, int start = 2)
{ 
    // Base cases 
    if (number <= 2) 
        return (number == 2) ? 1 : 0; 

    if (number % start == 0) 
      return 1; /* if the number is divisible by any other number but itself it will not be a prime number.*/
    
    if (start == (number-1))
      return 0;  
  
    // Check for numberext dstartvstartsor 
    return checkPrimeNumber(number, start + 1); 
} 

int main()
{
  int n;

  cout << "Enter a positive  integer: ";
  cin >> n;
  
  if(checkPrimeNumber(n) == 0)
    cout << n << " is a prime number.\n";
  else
    cout << n << " is not a prime number.\n";
  return 0;
}


