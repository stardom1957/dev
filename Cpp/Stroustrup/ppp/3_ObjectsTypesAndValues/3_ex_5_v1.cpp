#include "../std_lib_facilities.h"

int main()
{
    cout << "3_ex_5_v1.cpp v1\n";
    cout << "Please enter two floating point values: ";
    // double n;
    double val1;
    double val2;
    string comparisonResult{" "};

    while (cin >> val1 >> val2)
    {
      if (val1 < val2) comparisonResult = " is smaller then ";
      //if (val1 <= val2) comparisonResult = " is smaller then or equal to ";
      if (val1 > val2) comparisonResult = " is greater then ";
      //if (val1 >= val2) comparisonResult = " is greater then or equal to ";
      if (val1 == val2) comparisonResult = " is equal to ";
      cout << "val1 == " << val1
           << "\nval2 == " << val2
           << "\n" << val1 << comparisonResult << val2
           << "\nval1 + val2 == " << val1+val2
           << "\nval1 - val2 == " << val1-val2
           << "\nval1 * val2 == " << val1*val2
           << "\nval1 / val2 == " << val1/val2;
    cout << "\n\nPlease enter two integer values: ";
    }
    return 0;
}
