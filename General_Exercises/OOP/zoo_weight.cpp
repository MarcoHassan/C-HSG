/*
Write a function header for the ZooAnimal class member function
daysSinceLastWeighed.  This function has a single integer parameter
today and returns an integer number of days since the animal was last
weighed.
*/

#include <iostream>
#include <cstring>

using namespace std;

class ZooAnimal  
   {
    private:
      char *name;
      int cageNumber;
      int weightDate;
      int weight;
    public:
      void Create(char*, int, int, int);
      void Destroy (); // destroy function
      char* reptName ();
      int daysSinceLastWeighed(int);
   };

void ZooAnimal::Destroy ()
{	
  delete [] name;
}

char* ZooAnimal::reptName()
{
 return name;
}

void ZooAnimal::Create(char* shem, int mispar, int date, int miskal)
{
  name = new char[strlen(shem)+1];
  strcpy(name, shem);
  cageNumber = mispar;
  weightDate = date;
  weight = miskal;
}

// -------- member function to return the number of days
// -------- since the animal was last weighed
int ZooAnimal::daysSinceLastWeighed(int today)
{
 int startday, thisday;
 thisday = today/100*30 + today - today/100*100; // = today - 0.7today
 startday = weightDate/100*30 + weightDate - weightDate/100*100;
 if (thisday < startday) 
     thisday += 360;
 return (thisday-startday);
}

int main() {
  std::cout << "Hello World!\n";

  ZooAnimal cow;
  cow.Create((char*)"pah-RAH", 12, 360, 300); // note the casting

  cout << cow.daysSinceLastWeighed(12) << endl;

  return 0;
}

