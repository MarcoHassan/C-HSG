// Write a class having two private variables and one member function which will return the area of the rectangle.



#include <iostream>
using namespace std;

class CRectangle
{
  private:
    float width, length;

  public:
    float area(float, float);

  // constructor
  CRectangle(float, float);

};



int main () {

  float laenge, breite;
  cout<<"Enter length of rectangle: ";
  cin>>laenge;
  cout<<"Enter breadth of rectangle: ";
  cin>>breite;

  CRectangle rect(laenge, breite);
  cout <<"Area: "<< rect.area(laenge, breite) << endl;

  
  return 0;
}

/////////////////
// Constructor //
/////////////////

CRectangle::CRectangle(float breite, float laenge)
{
  width = breite;
  length = laenge;
  cout << "A Rectangle instance has been constructed." << endl;
}

float CRectangle::area(float breite, float laenge)
{
  return breite*laenge;
}
