// write a program that will form a new date from today's date, example new DateTime(2017,10,9)
// print that value
// finally, print also current datetime with the function Today

#include <iostream>
#include <ctime>
using namespace std;

// Function declaration
void Today();

// Function execution
int main() {
  std::cout << "Hello World!\n" << endl;

  Today();

  return 0;
}

// Function initialization
void Today()
{
   // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);

   // Method 1 //
   char exp[80];
   strftime(exp, sizeof(exp), "Today it's the %d-%m-%Y", ltm);
   puts(exp);


   /*Method 2
   // print various components of tm structure.
   int year = 1900 + ltm->tm_year;
   int month =  1 + ltm->tm_mon;
   int day =  ltm->tm_mday;

   cout << "Today it's the: (" << year << "," << month;
   cout << "," << day << ")" << endl;
   */
}





    
    
      
