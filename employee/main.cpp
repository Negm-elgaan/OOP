#include "Person.cpp"

using namespace std;
class ClsEmployee : ClsPerson
{
    float _Salary ;
    string _Title ;
    string _Department ;
    string _MainProgrammingLanguage ;
    public:
        ClsEmployee(string Title , string Department , float Salary , string  MainProgrammingLanguage , short id , string Firstname , string Lastname , string Email , string Phone) : ClsPerson(id,Firstname,Lastname,Email,Phone)
        {
            _Title = Title ;
            _Department = Department ;
            _Salary = Salary ;
            _MainProgrammingLanguage = MainProgrammingLanguage ;
        }
        void SetDepartment(string Department)
        {
            _Department = Department ;
        }
        string GetDepartment()
        {
            return _Department ;
        }
        void SetTitle(string Title)
        {
            _Title = Title ;
        }
        string GetTitle()
        {
            return _Title ;
        }
        void SetSalary(float Salary)
        {
            _Salary = Salary ;
        }
        float GetSalary()
        {
            return _Salary ;
        }
        void SetMainProgrammingLanguage(string MainProgrammingLanguage)
        {
            _MainProgrammingLanguage = MainProgrammingLanguage ;
        }
        string GetMainProgrammingLanguage()
        {
            return _MainProgrammingLanguage ;
        }
        void Print()
        {
            cout << "Info\n\n";
            cout << "__________________________________\n";
            cout << "ID" << right << setw(24) << ":" << _Id << endl;
            cout << "FirstName" << right << setw(17) << ":" << _FirstName << endl;
            cout << "LastName" << right << setw(18) << ":" << _LastName << endl;
            cout << "Full name" << right << setw(17) << ":" << _FirstName + " " + _LastName << endl;
            cout << "Email" << right << setw(21) << ":" << _Email << endl;
            cout << "Phone" << right << setw(21) << ":" << _Phone << endl;
            cout << "Title" << right << setw(21) << ":" << _Title << endl;
            cout << "Department" << right << setw(16) << ":" << _Department << endl;
            cout << "Salary" << right << setw(20) << ":" << _Salary << endl;
            cout << "Main Programming Language" << ":" << _MainProgrammingLanguage << endl;
            cout << "__________________________________\n";
        }
        ~ClsEmployee()
        {
            cout << "Object destroyed!\n" ;
        }
};
int main()
{
    ClsEmployee Emp("CEO","CS",250000,"C++",10,"Mohammed","Abu-Hadhoud","my@gmail.com","02831199200");
    Emp.Print();
    return 0;
}
