/*
In the main function there is a cout statement that attempts to
print the animal's name.  However, it is not allowable because it
attempts to access the private data member called name.  Modify that
statement so that it uses a public member function that returns the
ZooAnimal's name.

   class ZooAnimal  
   {
    private:
      char *name;
      int cageNumber;
      int weightDate;
      int weight;
    public:
      void Create (char*, int, int, int); // create function
      void Destroy (); // destroy function 
      char* reptName ();
      int daysSinceLastWeighed (int today);
   };

   // -------- member function to return the animal's name
   char* ZooAnimal::reptName ()
   {
    return name;
   }
   
  


*/

#include <iostream>

class ZooAnimal  
   {
    private:
      char *name;
      int cageNumber;
      int weightDate;
      int weight;
    public:
      void Destroy (); // destroy function
      char* reptName ();
      int daysSinceLastWeighed (int today);
   };
    void ZooAnimal::Destroy ()
   {	
    delete [] name;
   }

   // -------- member function to return the animal's name
   char* ZooAnimal::reptName ()
   {
    return name;
   }
   
 // ========== an application to use the ZooAnimal class
int main ()
   {
    ZooAnimal bozo;
    bozo.Create ("Bozo", 408, 1027, 400);

    cout << "This animal's name is " << bozo.name << endl;

    bozo.Destroy ();
   }
