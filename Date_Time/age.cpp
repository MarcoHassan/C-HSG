// Write a program that calculates one's age based on the date of birth of the person that is asked as input

#include <iostream>
#include <time.h> /* time_t, struct tm, difftime, time, mktime */
#include <string>

using namespace std;

// Function definition
void yearsOfLife (const char* date);

int main() {

  string date_birth;

  cout << "Please enter your date of birth in the following form dd/mm/yyyy: ";

  cin >> date_birth;

  yearsOfLife(date_birth.c_str()); // c_str to convert the inserted string to a const char*.

   return 0;
}

// Function initialization
void yearsOfLife (const char* date)
{
  time_t now = time(0);

  const char* birthday = date;
  struct tm timeBirth;

  strptime(birthday, "%d/%m/%Y", &timeBirth);

   // Convert now to struct tm.
   tm* current = localtime(&now);

   // Get the time elapsed between the dates.
   cout << "Your age is: ";

   // Complex alternative //

   
   if(current->tm_mon < timeBirth.tm_mon)
     {
       cout << current->tm_year - timeBirth.tm_year -1 << " years" << endl;
     }

   else if(current->tm_mon == timeBirth.tm_mon)
     {
       if(current->tm_mday < timeBirth.tm_mday)
	 {
	   cout << current->tm_year - timeBirth.tm_year -1 << " years" << endl;
	 }
       else
	 {
	   cout << current->tm_year - timeBirth.tm_year << " years" << endl;
	 }
     }

   else
     {
       cout << current->tm_year - timeBirth.tm_year << " years" << endl;
     }
}
