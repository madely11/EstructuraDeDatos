#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
/*
int main(int argc, char *argv[])
{
	char cad[10];
	char a='8';
	try{
        throw a;
    }
    catch(char cad) {
        cout << "Entero excepcion lanzada" << cad <<endl;
    }
	system("pause");
	return 0;
}
*/

#include <exception>

using namespace std;

class derivedexception: public exception {
      virtual const char* what() const throw() {
        return "My derived exception";
      }
} myderivedexception;

int main () {
      try {
        throw myderivedexception;
      }
      catch (exception& e) {
        cout << e.what() << '\n';
      }
      system("pause");
}

