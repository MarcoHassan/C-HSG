// Complete the below program so if checks the input v1 and answers 'Good! Me too!' if the answer is Yes and 'That's a shame. It's fun!' if the answer is No

#include <iostream>
#include <string>
using namespace std;

int main() {
  std::cout << "Do you like programming?\n";
  string v1;
  cin >> v1;
  
  v1 == "Yes" ? printf("%s", "Good! Me too!\n") :\
    printf("%s", "That's a shame. It's fun!\n"); 
 
  return 0;
}
