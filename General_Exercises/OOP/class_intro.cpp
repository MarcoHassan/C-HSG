// The below example uses an Object rectangle
/*
Class Rectangle useds 2 public members

Tasks
- add 2 private members shape and rounded (both integers)
- add 1 protected member color (integer)
- add 1 new public method color - assign color black to it (value of 1) and then print it out fromt he main

// IMPORTANT: private is the default access level!!

*/
#include <iostream>
using namespace std;

class Rectangle {
    int width, height; // both are private as this is the default.

  public: /* the members - both variables and functions - can be accessed
	     from anywhere */
    void set_values (int,int);
    int area() {return width*height;};
    void set_color(int color);

  protected: /* the members can be accessed inside this Rectangle class
		by friend functions/classes and derived classes */

    int color;

  private: /* these members can be acessed inside the class and by 
	      friend classes/functions but not by derived classes */
    int shape, rounded;
};

void Rectangle::set_values (int x, int y)
{
  width = x;
  height = y;
}

void Rectangle::set_color(int x)
{
  color = x;

  cout << "The color was set to: " << color << endl;
}

int main () {
  Rectangle rect;
  rect.set_values (3,4);
  cout << "area: " << rect.area() << endl;

  rect.set_color(1);
  
  return 0;
}
