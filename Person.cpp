#include <iostream>
#include <iomanip>

using namespace std;
class ClsPerson
{
    short _Id ;
    string _FirstName ;
    string _LastName ;
    string _Email ;
    string _Phone ;
    public :
        ClsPerson(short id , string Firstname , string Lastname , string Email , string Phone)
        {
            _Id = id ;
            _FirstName = Firstname ;
            _LastName = Lastname ;
            _Email = Email ;
            _Phone = Phone ;
        }
        void SetEmail(string email)
        {
            _Email = email ;
        }
        string GetEmail()
        {
            return _Email ;
        }
        void SetFirstName(string firstname)
        {
            _FirstName = firstname ;
        }
        string GetFirstName()
        {
            return _FirstName ;
        }
        void SetLastName(string lastname)
        {
            _LastName = lastname ;
        }
        string GetLastName()
        {
            return _LastName ;
        }
        void SetPhone(string phone)
        {
            _Phone = phone;
        }
        string GetPhone()
        {
            return  _Phone ;
        }
        short GetId()
        {
            return _Id ;
        }
        void SendEmail(string subject , string body)
        {
            cout << "The following message sent successfully to email : " << _Email << endl;
            cout << "Subject : " << subject << endl;
            cout << "Body : " << body << endl;
        }
        void SendSMS(string sms)
        {
            cout << "The Following SMS sent successfully to phone : " << _Phone << endl << sms << endl;
        }
        void Print()
        {
            cout << "Info\n\n";
            cout << "______________________\n";
            cout << "ID" << right << setw(10) << ":" << _Id << endl;
            cout << "FirstName" << right << setw(3) << ":" << _FirstName << endl;
            cout << "LastName" << right << setw(4) << ":" << _LastName << endl;
            cout << "Full name" << right << setw(3) << ":" << _FirstName + " " + _LastName << endl;
            cout << "Email" << right << setw(7) << ":" << _Email << endl;
            cout << "Phone" << right << setw(7) << ":" << _Phone << endl;
            cout << "______________________\n";
        }

};
int main()
{   
	return 0;
}

