/* Structure or Typedef is used when you want to specify your user defined data types 
 Modify the below code so it prints all three car types one after the other.

 output: 
Cartype:Toyota
Cartype:Honda
Cartype:Ford

*/

#include "stdio.h"
#include <string.h>

struct CarTypes {
  char carname[100]; 
};

// you can use typdef also - example is given below
// typedef struct CarTypes {
//   char carname[100];
// } CarType;

int main(void) {

  /* Declare the Cartyèes 3 variables */
  struct CarTypes cartype1;
  struct CarTypes cartype2;
  struct CarTypes cartype3;

  // Specify the Cartypes 
  strcpy(cartype1.carname, "Toyota");
  strcpy(cartype2.carname, "Honda");
  strcpy(cartype3.carname, "Ford");

  // Print the Cartypes
  printf("Cartype:%s\nCartype:%s\nCartype:%s\n",cartype1.carname, cartype2.carname, cartype3.carname);
  return 0;
}
