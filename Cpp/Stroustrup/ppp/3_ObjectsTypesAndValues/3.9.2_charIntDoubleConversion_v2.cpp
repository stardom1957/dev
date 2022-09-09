#include "../std_lib_facilities.h"
/*
accepte une valeur double et procède à diverses conversions vers int et char.
ppp., page 81

ce programme donnera des avertissements, car des «narrowing conversion sont utilisées»
*/

int main()
{
    cout << "3.9.2_charIntDoubleConversion v2\nUsing {} intitialization, thus, avoiding narrowing conversion.";
    double d = 0;
    while (cin>>d) {
      int i {d};  //try to squeeze a double into an int
      char c {i}; // try to squeeze an int into a char
      int i2 {c}; // get the int value of the char
      cout << "d== " << d << " i== " << i << " i2== " << i2 << " car== " << c << "\n";
    }
}
