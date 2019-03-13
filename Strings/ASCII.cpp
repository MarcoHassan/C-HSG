/* below code should count nb of vowels, Consonants, digits and white spaces.
  Make sure it counts and prints the number of Consonants, digits and white spaces
*/

#include <iostream>
#include <ctype.h> // to convert the string to lowercase
using namespace std;

int convertToASCII(char entry)
{
  return (int)entry;
}

int main()
{
    char line[150];
    int vowels, consonants, digits, spaces;
    char c;

    vowels =  consonants = digits = spaces = 0;

    cout << "Enter a line of string: ";
    cin.getline(line, 150);

    for(int i = 0; line[i]!='\0'; ++i)
    {
      c = tolower(line[i]);
      int help = convertToASCII(c);

      bool vowel = c=='a' || c=='e' || c=='i' || c=='o' || c=='u';

      if(c >= 97 && c <=122)
	{
	  if(vowel != 1)
	    {
	      consonants++;
	    }

	  else
	    {
	      vowels++;
	    }
	}

      if(help >= 48 && help <= 57)
	{
	  digits++;
        }

      if(help == 32)
	{
	  spaces++;
	}
					
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "White spaces: " << spaces << endl;

    return 0;
}
