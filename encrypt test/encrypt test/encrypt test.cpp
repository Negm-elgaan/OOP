// encrypt test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
using namespace std;
class Encrypt
{
    string _word;
    static long long int x;
    long long int NumOfEncryptions;
    static long long int y;
    static long long int w;

    void _Encrypt()
    {
        NumOfEncryptions++;
        for (int i = 0; _word[i] != '\0'; i++)
        {
            _word[i] = char((long long int)_word[i] + x);
        }
        x = (x * 2) + 1;
        
    }

    void _Decrypt()
    {
        int z = x;

        for (int i = 0; i < NumOfEncryptions; i++)
        {
            z = (z - 1) / 2;
            for (long long int j = 0; _word[j] != '\0'; j++)
                _word[j] = char((long long int)_word[j] - z);
        }
        NumOfEncryptions = 0;
    }

    public:

        Encrypt()
        {
            NumOfEncryptions = 0;
        }

        void SetWord(string word)
        {
            _word = word;
        }

        string GetWord()
        {
            return _word;
        }

        void Encryption(int num = 3)
        {
            
            for (long long int i = 0; i < num + y; i++)
            {
                _Encrypt();
                cout << _word << endl;
            }
            y = (y * 2) + (w * 3);
            w = (w * 2) * -1;
            cout << y << "    " << w <<  "    " << x << endl;
        }

        void Decrypt()
        {
            return _Decrypt();
        }
};
long long int Encrypt::x = 1;
long long int Encrypt::y = 1;
long long int Encrypt::w = 1;
int main()
{
    Encrypt word;
    word.SetWord("zzzz");
    
    /*word.Encrpyt();
    cout << word.GetWord() << endl;

    word.Encrpyt();
    cout << word.GetWord() << endl;

    word.Encrpyt();
    cout << word.GetWord() << endl;
    */
    word.Encryption();

    word.Decrypt();
    cout << word.GetWord() << endl;

    cout << endl;

    Encrypt word2;
    word2.SetWord("aaaa");

    /*word2.Encrpyt();
    cout << word2.GetWord() << endl;

    word2.Encrpyt();
    cout << word2.GetWord() << endl;

    word2.Encrpyt();
    cout << word2.GetWord() << endl;
    */
    word2.Encryption();

    word2.Decrypt();
    cout << word2.GetWord() << endl;

    cout << endl;

    Encrypt word3;
    word3.SetWord("NEGM");
    /*
    word3.Encrpyt();
    cout << word3.GetWord() << endl;

    word3.Encrpyt();
    cout << word3.GetWord() << endl;

    word3.Encrpyt();
    cout << word3.GetWord() << endl;
    */
    word3.Encryption();
    word3.Decrypt();
    cout << word3.GetWord() << endl;

    cout << endl;

    /*word.Encrpyt();
    cout << word.GetWord() << endl;

    word.Encrpyt();
    cout << word.GetWord() << endl;

    word.Encrpyt();
    cout << word.GetWord() << endl;

    
    */
    word.Encryption();
    word.Decrypt();
    cout << word.GetWord() << endl;

    cout << endl;

    Encrypt Word1;
    Word1.SetWord("NEGM-ELG3AN");

    Word1.Encryption();
    Word1.Decrypt();
    cout << Word1.GetWord() << endl;

    //word.Encrpyt();
    //cout << word.GetWord() << endl;
    
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
