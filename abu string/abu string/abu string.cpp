// abu string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
//My Class
class clsString
{

private:
    string _Value;
public:

    clsString()
    {
         _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }
    void SetValue(string Value) {
        _Value = Value;
    }
    string GetValue() {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue)) string Value;
    static short length(string s1)
    {
        short c = 0;
        for (int i = 0; s1[i] != NULL; i++)
            c++;
        return c;
    }
    short length()
    {
        return length(_Value);
    }
    static bool IsCharLower(char c)
    {
        return (c >= 97 && c <= 122);
    }
    static bool IsCharUpper(char c)
    {
        return (c >= 65 && c <= 90);
    }
    static bool islower(string value)
    {
        for (int i = 0; value[i] != '\0'; i++)
            if (!IsCharLower(value[i]))
                return false;
        return true;
    }
    bool islower()
    {
        return islower(_Value);
    }
    static bool isupper(string value)
    {
        for (int i = 0; value[i] != '\0'; i++)
            if (!IsCharUpper(value[i]))
                return false;
        return true;
    }
    bool isupper()
    {
        return isupper(_Value);
    }
    static short CountWords(string S1)
    {

        string delim = " "; // delimiter
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }
    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && IsCharUpper(S1[i]))
                Counter++;
            if (WhatToCount == enWhatToCount::SmallLetters && IsCharLower(S1[i]))
                Counter++;
        }
        return Counter;
    }
    short CountLetters()
    {
        return CountLetters(_Value);
    }
    short CountWords()
    {
        return CountWords(_Value);
    };
    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }
    //__declspec(property(get = , put = SetValue)) string Value;
    
    static bool checkvowel(char c)
    {
        c = tolower(c);
        return (c == 'a' || c == 'i' || c == 'e' || c == 'u' || c == 'o');
    }
    static short CountVowels(string s)
    {
        short counter = 0 ;
        for (int i = 0 ; s[i] != NULL ; i++)
            if(checkvowel(s[i]))
                counter++;
        return counter;
    }
    short CountVowels()
    {
        return CountVowels(_Value); 
    }
    static void printvowels(string s)
    {
        cout << "Vowels in string are : " ;
        for (int i = 0 ; s[i] != NULL ; i++)
            if(checkvowel(s[i]))
                cout << s[i] << setw(4) ;
    }
    void printvowels()
    {
        printvowels(_Value);
    }
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }
    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }
    static string to_lower(string &s)
    {
        for (int i = 0 ; s[i] != NULL ; i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 32 ;
        }
        return s;
    }
    void to_lower()
    {
        _Value = to_lower(_Value);
    }
    static string to_upper(string &s)
    {
        for (int i = 0 ; s[i] != NULL ; i++)
        {
            if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32 ;
        }
        return s;
    }
    void to_upper()
    {
        _Value = to_upper(_Value);
    }
    static char invertcase(char &c)
    {
        if (c >= 97 && c <= 122)
            return c -= 32 ;
        else if (c >= 65 && c <= 90)
            return c += 32 ;
    }
    static string invertcaser(string &s)
    {
        for (int i = 0 ; s[i] != NULL ; i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 32 ;
            else if (s[i] >= 97 && s[i] <= 122)
                s[i] -= 32 ;
        }
        return s;
    }
    void invertcaser()
    {
        _Value = invertcaser(_Value);
    }
    static short CountCaptial(string &s)
    {
        short c = 0 ;
        for (int i = 0 ; s[i] != NULL ; i++)
            if (s[i] >= 65 && s[i] <= 90)
                c++;
        return c ;
    }
    short CountCaptial()
    {
        return CountCaptial(_Value);
    }
    static short CountSmall(string &s)
    {
        short c = 0 ;
        for (int i = 0 ; s[i] != NULL ; i++)
            if (s[i] >= 97 && s[i] <= 122)
                c++;
        return c ;
    }
    short CountSmall()
    {
        return CountSmall(_Value);
    }
    static short PrintEachWordInString(string S1)
    {
        short counter = 0 ;
        string delim = " "; // delimiter
        cout <<"\nYour string words are: \n\n";
        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            counter++;
            sWord =S1.substr(0, pos);// store the word
            if (sWord !="")
            {
                cout << sWord << endl;
            }
            S1.erase(0, pos + delim.length());  // erase() until positon and move to next word.
        }
        if (S1!="")
        {
            cout <<S1<< endl; // it print last word of the string.
            counter++;
        }
        return counter ;
    }
    short PrintEachWordInString()
    {
        return PrintEachWordInString(_Value);
    }
    static vector<string> SplitString(string S1, string Delim)
    {
        vector<string> vString;
        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord =S1.substr(0, pos); // store the word
            if (sWord !="")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }
        return vString;
    }
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }
    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }
    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }
    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));
    }
    static string Join(vector <string> vString, string delim)
    {
        string s1 = "";
        for (int i = 0; i < vString.size(); i++)
        {
            if (i == vString.size() - 1)
                s1 += vString[i];
            else
                s1 += vString[i] + delim;
        }
        return s1;
    }
    /*string JoinString(vector<string> vString, string Delim)
    {
        string S1 = "";
        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }
    string Join(short n, string arr[], string delim)
    {
        for (short i = 0; i < n; i++)
            cin >> arr[i];
        string s = "";
        for (short i = 0; i < n; i++)
        {
            s += arr[i] + delim;
        }
        return s.substr(0, s.length() - delim.length());
    }*/   
}; 
// ABU Class
class clsString2
{

private:
    string _Value;

public:

    clsString2()
    {
        _Value = "";
    }

    clsString2(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;


    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _Value.length();
    };

    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static string  UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string  LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  LowerFirstLetterOfEachWord()
    {


        // no need to return value , this function will directly update the object value  
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string  UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void  UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string  LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string  InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {


        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

    static short  CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short  CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

    static short  CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string S1)
    {


        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {


        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));

    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());


    }

    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }

    static string ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }


};

int main()
{
    clsString String1;
    clsString String2("Mohammed");

    String1.Value = "Ali Ahmed";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl;


    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Mohammed Saqer Abu-Hadhoud");



    system("pause>0");
    return 0;
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
