#include <iostream>
//string addressline1 , string addressline2 , string city , string country
using namespace std;
class clsPerson
{
    class clsAddress
    {
            string AddressLine1;
            string AddressLine2;
            string City;
            string Country;
            public:
                clsAddress(string addressline1 , string addressline2 , string city , string country)
                {
                    AddressLine1 = addressline1 ;
                    AddressLine2 = addressline2 ;
                    City = city ;
                    Country = country ;
                }
                clsAddress()
                {
                    AddressLine1 = "Building 10";
                    AddressLine2 = "Queen Rania Street";
                    City = "Amman";
                    Country = "Jordan";
                }
                void SetAddressLine1(string addressline1)
                {
                    AddressLine1 = addressline1 ;
                }
                string GetAddressLine1()
                {
                    return AddressLine1 ;
                }
                void SetAddressLine2(string addressline2)
                {
                    AddressLine2 = addressline2 ;
                }
                string GetAddressLine2()
                {
                    return AddressLine2 ;
                }
                void SetCity(string city)
                {
                    City = city ;
                }
                string GetCity()
                {
                    return City ;
                }
                void SetCountry(string country)
                {
                    Country = country ;
                }
                void Print()
                {
                    cout << "\nAddress:\n";
                    cout << AddressLine1 << endl;
                    cout << AddressLine2 << endl;
                    cout << City << endl;
                    cout << Country << endl;
                }
    };
    public:
        string FullName;
        clsAddress Address{"HI","tut","GGG","kgj"};
        clsPerson()
        {
            FullName = "Mohammed Abu-Hadhoud";
        }
};
class ClsPerson
{
    string _FullName;
    class clsAddress
    {
        private :
            string _AddressLine1;
            string _AddressLine2;
            string _City;
            string _Country;
            public:
                clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
                {
                    _AddressLine1 =AddressLine1;
                    _AddressLine2 =AddressLine2;
                    _City =City;
                    _Country=Country;
                }
                string setAddressLine1(string AddressLine1)
                {
                    _AddressLine1 =AddressLine1;
                }
                string AddressLine1()
                {
                    return _AddressLine1 ;
                }
                string setAddressLine2(string AddressLine2)
                {
                    _AddressLine2 =AddressLine2;
                }
                string AddressLine2()
                {
                    return _AddressLine2;
                }
                string setCity(string City)
                {
                    _City =City;
                }
                string City()
                {
                     return _City;
                }
                string setCountry(string Country)
                {
                    _Country =Country;
                }
                string Country()
                {
                    return _Country;
                }
                void Print()
                {
                    cout <<"\nAddress:\n";
                    cout << _AddressLine1 << endl;
                    cout << _AddressLine2 << endl;
                    cout << _City << endl;
                    cout << _Country << endl;
                }
    };
    public:
        string setFullName(string FullName)
        {
            _FullName =FullName;
        }
        string FullName()
        {
            return _FullName ;
        }
        clsAddress Address =  clsAddress("", "","","");
        ClsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
        {
            _FullName =FullName; //initiate address class by it's constructor
            Address =clsAddress (AddressLine1, AddressLine2, City, Country);
        }
};
int main()
{
    clsPerson Person1 ;
    cout << Person1.FullName<<endl;
    Person1.Address.Print();
    cout << "Hello world!" << endl;
    return 0;
}
