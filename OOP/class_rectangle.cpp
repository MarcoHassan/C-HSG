// Write a class having two private variables and one member function which will return the area of the rectangle.



#include <iostream>
using namespace std;

class CRectangle {

  

};



int main () {

  CRectangle rect;
  cout<<"Enter length of rectangle:";
  cin>>rect.x;
  cout<<"Enter breadth of rectangle:";
  cin>>rect.y;
  cout <<"Area:"<< rect.area();

  
  return 0;
}
