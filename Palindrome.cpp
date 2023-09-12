#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main()
{
  char input[80];
  char cleaninp[80];
  cout << "Please type in your string?" << endl;
  cin.get(input, 80, '\n');
  cout << input << endl;

  
  
  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }

  cout << input << endl;

  int charcount = 0;
  bool isalp = false;
  bool isdig = false;
  
  for (int i = 0; i < strlen(input); i++) {

    if (isalpha(input[i] !=0)) {
      isalp = true;
    }
    else {
      isalp = false;
    }

    if (isdigit(input[i] !=0)) {
      isdig = true;
    }
    else {
      isdig = false;
    }

      
    if (isdig == true && isalp == true) {

      cout << "Im here!" << endl;
      cleaninp[charcount] = input[i];
      charcount++;
    }
  }

  /**for (int i = 0; i < strlen(input); i++) {
    cout << "Digit? " << isdigit(input[i]) << " Alpha? " << isalpha(input[i]) << endl;
    }**/
  
  cout << cleaninp << endl;
  
}
