/*
The ZooAnimal class definition below is missing a prototype for
the Create function.  It should have parameters so that a character
string and three integer values (in that order) can be provided when
it is called for a ZooAnimal object.  Like the Destroy function, it
should have return type void.  Write an appropriate prototype for the
ZooAnimal Create function.
*/
#include <iostream>
#include <cstring> /* for strlen and strcpy */

using namespace std;

class ZooAnimal  
 {
  private:
    char *name;
    int cageNumber;
    int weightDate;
    int weight;
   
  public:
    void Create (char*, int, int, int);
    void Destroy (); // destroy function
    char* reptName ();
    int daysSinceLastWeighed (int today);
 };
   
int main() {
  std::cout << "Hello World!\n";

  ZooAnimal cow;

  cow.Create((char*)"pah-RAH", 12, 1998, 300);

  return 0;
}

void ZooAnimal::Create(char* shem, int mispar, int date, int miskal)
{
  name = new char[strlen(shem)+1];
  strcpy(name, shem);
  cageNumber = mispar;
  weightDate = date;
  weight = miskal;
}
