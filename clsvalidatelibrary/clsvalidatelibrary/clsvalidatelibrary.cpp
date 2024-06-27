// clsvalidatelibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "clsdate.h"
using namespace std;

class clsInputValidate
{
public:
    clsInputValidate()
    {
        return;
    }
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number > From) && (Number < To);
    }
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number > From) && (Number < To);
    }
    static bool IsDateBetween(clsDate Date , clsDate From , clsDate To)
    {
        if (clsDate::IsDate1AfterDate2(To,From))
            return (clsDate::IsDate1AfterDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To));
        else
            return (clsDate::IsDate1BeforeDate2(Date, From)) && (clsDate::IsDate1AfterDate2(Date, To));
    }
    static int ReadIntNumber(string message)
    {
        string test;
        int num = 0;
        cin >> test;
        for (int i = 0; test[i] != NULL; i++)
        {
            if (!(test[i] >= 48 && test[i] <= 57))
            {
                cout << message << endl;
                cin >> test;
                i = 0;
                num = 0;
            }
            num = num * 10 + int(test[i] - 48);
        }
        return num;
    }
    static double ReadDblNumber(string message)
    {
        string test;
        int number = 0;
        double num = 0;
        cin >> test;
        for (int i = 0; test[i] != NULL; i++)
        {
            if (test[i] == 46)
            {
                if (number < 1)
                {
                    number++;
                    i++;
                }
            }
            if (!(test[i] >= 48 && test[i] <= 57))
            {
                cout << message << endl;
                cin >> test;
                i = 0;
                number = 0;
            }
        }
        num = stod(test);
        return num;
    }
    static int ReadNumberBetween(int From , int To , string message)
    {
        int num = 0;
        if (From < To)
        {
            cin >> num;
            while (!(num < To && num > From))
            {
                cout << message << endl;
                cin >> num;
            }
        }
        else
        {
            cin >> num;
            while (!(num > To && num < From))
            {
                cout << message << endl;
                cin >> num;
            }
        }
        return num;
    }
    static double ReadNumberBetween(double From, double To, string message)
    {
        double num = 0;
        if (From < To)
        {
            cin >> num;
            while (!(num < To && num > From))
            {
                cout << message << endl;
                cin >> num;
            }
        }
        else
        {
            cin >> num;
            while (!(num > To && num < From))
            {
                cout << message << endl;
                cin >> num;
            }
        }
        return num;
    }
    static	bool IsValidDate(clsDate Date)
    {

        if (Date.Day < 1 || Date.Day>31)
            return false;

        if (Date.Month < 1 || Date.Month>12)
            return false;

        if (Date.Month == 2)
        {
            if (clsDate::isLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }

        short DaysInMonth = clsDate::NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;

        return true;
    }
};
//  Abu-Hadhoud Class:
class ClsInputValidate
{

public:

    static bool IsNumberBetween(short Number, short From, short To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;

    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        //Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            )
        {
            return true;
        }

        //Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            )
        {
            return true;
        }

        return false;
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return	clsDate::IsValidDate(Date);
    }

};


int main()
{
    double y = 123.929292;
    cout << y << endl;
    int x = clsInputValidate::ReadIntNumber("invalid");
    cout << x << endl;
    double z = clsInputValidate::ReadDblNumber("invalid");
    cout << z << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(20, 10, 2022), clsDate(300, 2024));
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
