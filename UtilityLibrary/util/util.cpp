// util.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "ClsDate.h"

using namespace std;

class UtilityLibrary
{
public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    static string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
    static string  DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }
    static char RandomNumber2(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, Mix = 5 };
    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        default:
        {
            return char(RandomNumber(1, 127));
        }
        }
    }
    static void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                arr[i][j] = RandomNumber(1, 100);
            }
        }
    }
    static void PrintMatrix(int arr[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                cout << setw(3) << arr[i][j] << "     ";
            }
            cout << "\n";
        }
    }
    static int RowSum(int arr[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;
        for (short j = 0; j <= Cols - 1; j++)
        {
            Sum += arr[RowNumber][j];
        }
        return Sum;
    }
    static int ColSum(int arr[3][3], short Cols, short Rows)
    {
        int Sum = 0;
        for (short j = 0; j <= Rows - 1; j++)
        {
            Sum += arr[j][Cols];
        }
        return Sum;
    }
    static void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
    {
        cout << "\nThe following are the sum of each row in the matrix:\n";
        for (short i = 0; i < Rows; i++)
        {
            cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
        }
    }
    static void PrintEachColSum(int arr[3][3], short Rows, short Cols)
    {
        cout << "\nThe following are the sum of each Column in the matrix:\n";
        for (short i = 0; i < Cols; i++)
        {
            cout << "Column " << i + 1 << " Sum = " << ColSum(arr, i, Rows) << endl;
        }
    }
    static void getsum(int arr[3][3], short Rows, short Cols)
    {
        int sum = 0;
        cout << "The following are the sum of each row in the matrix: \n";
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                sum += arr[i][j];
            }
            cout << "Row " << i + 1 << " sum = " << sum;
            cout << "\n";
            sum = 0;
        }
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }
    static void getsumofrowsbyarr(int arr[3][3], short Rows, short Cols, int arr1[3])
    {
        for (int i = 0; i < Rows; i++)
            arr1[i] = RowSum(arr, i, Cols);
    }
    static void getsumofcolsbyarr(int arr[3][3], short Rows, short Cols, int arr1[3])
    {
        for (int i = 0; i < Cols; i++)
            arr1[i] = ColSum(arr, i, Rows);
    }
    static void printsumofcolsinarr(int arr1[3], short Cols)
    {
        cout << "The following are the sum of each column in the matrix in an array: \n";
        for (int i = 0; i < Cols; i++)
            cout << "Col " << i + 1 << " sum = " << arr1[i] << endl;
    }
    static void printsumofrowsinarr(int arr1[3], short Rows)
    {
        cout << "The following are the sum of each row in the matrix in an array: \n";
        for (int i = 0; i < Rows; i++)
            cout << "Row " << i + 1 << " sum = " << arr1[i] << endl;
    }
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }
    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }
    static void GenerateKeys(short NumberOfKeys)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }
    static string GenKeys(int num)
    {
        string key = "";
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j < 20; j++)
            {
                if (j >= 5 && j % 5 == 0)
                    key += '-';
                else
                    key += RandomNumber2(65, 90);
            }
            cout << "Key[" << i << "]: " << key << endl;
            key = "";
        }
    }
    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(bool& A, bool& B)
    {
        bool Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(char& A, char& B)
    {
        char Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void  SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;
        TempDate.Year = Date1.Year;
        TempDate.Month = Date1.Month;
        TempDate.Day = Date1.Day;
        Date1.Year = Date2.Year;
        Date1.Month = Date2.Month;
        Date1.Day = Date2.Day;
        Date2.Year = TempDate.Year;
        Date2.Month = TempDate.Month;
        Date2.Day = TempDate.Day;
    }
    static string DateToString(clsDate Date)
    {
        return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }
    static string Tabs(short num)
    {
        string Tabs = "";
        for (short i = 0; i < num; i++)
            Tabs += "   ";
        return Tabs;
    }
    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength)], arr[RandomNumber(1, arrLength)]);
        }
    }
    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength)], arr[RandomNumber(1, arrLength)]);
        }
    }
    static void ArrayOfKeys(string arr[100], int NumberOfKeys)
    {
        for (int i = 0; i < NumberOfKeys; i++)
            arr[i] = GenerateKey();
    }
    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    static void randomarr(int arr[3][3])
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = RandomNumber(0, 100);
    }
    static void printarr(int arr[3][3])
    {
        cout << "The following is a 3x3 random matrix:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
};
int main()
{
    srand((unsigned)time(NULL));
    cout << "Hello world!" << endl;
    return 0;
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
