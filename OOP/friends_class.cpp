// In the below  example, class Rectangle is a friend of class Square allowing Rectangle's member functions to access private and protected members of Square. 

// Can you add a new function Rectangle::convert (defined by void convert (Square a) which will accesses the member variable Square::side, which describes the side of the square.

#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
// TODO add convert definition here
   
};

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};

// TODO add convert code here

  
int main () {
  Rectangle rect;
  Square sqr (4);
  rect.convert(sqr);
  cout << rect.area();
  return 0;
}
