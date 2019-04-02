// Debug the below program that calculates the number of days between two dates and then print the difference
// There are 2 mistakes - find and correct them

#include <iostream>
#include <ctime>

int main()
{
    struct std::tm a = {0,0,0,24,5,118}; /* June 24, 2018 */
    struct std::tm b = {0,0,0,5,6,118}; /* July 5, 2018 */
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1))
    {
      double difference = std::difftime(y, x) /  (60 * 60 * 24);
      // above -> conversion from seconds to min -> to h -> to days
        std::cout << std::ctime(&x);
        std::cout << std::ctime(&y);
        std::cout << "difference = " << difference << " days" << std::endl;
    }

    return 0;
}

// Notice //
/* (std::time_t)(-1) is returned when time falis to initialize the object. */
