#include "../std_lib_facilities.h"

int main()
{file:///home/dominique/devC/Stroustrup/ppp/3_ObjectsTypesAndValues/3.3_nameAndAge_v2.cpp

    cout << "Please enter your first name and age:\n";
    string first_name = "unknown";
    string last_name = "unknown";
    double age = 0;
    cin >> first_name >> last_name >> age;
    cout << "Hello, " << first_name << " " << last_name << " (age " << age * 12 << " months)\n";
    return 0;
}
