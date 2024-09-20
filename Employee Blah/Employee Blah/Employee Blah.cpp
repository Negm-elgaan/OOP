// Employee Blah.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Employee
{
    int ID;
    string Name;
    mutable int Count = 0;
    public:
        Employee(int ID , string Name)
        {
            this->ID = ID;
            this->Name = Name;
        }
        Employee()
        {
            cin >> ID;
            cin >> Name;
        }
        const int GetID() const
        {
            Count++;
            return ID;
        }
        const int GetCount() const
        {
            return Count;
        }
};
int main()
{
    const Employee Admin(1111,"Negm");
    cout << Admin.GetID() << endl;
    cout << Admin.GetCount();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file