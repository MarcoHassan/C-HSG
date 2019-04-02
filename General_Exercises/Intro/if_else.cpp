/* Now let's extend the previous task.

 At the moment, nothing happens if you answer "maybe"
 Complete the program so that when the user answers maybe, the computer replies Keep // practising!
Do you like programming?
  >maybe
  Keep practising!
  */
  

#include <iostream>
#include <string>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  std::cout << "Do you like programming?\n";
  string v1;
  cin >> v1;
  
  if(v1 == "Yes")
    {
      printf("%s", "Good! Me too!\n");		\
    }
  else if (v1 == "maybe")
    {
    printf("%s", "Keep practising!\n"); 
    }
  else
    {
    printf("%s", "That's a shame. It's fun!\n"); 
    }
    
 
  return 0;
}
