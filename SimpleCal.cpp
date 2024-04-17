#include <iostream>

using namespace std;

class SimpleCalculator
{
    float num ;
    public :
        void Add(float number)
        {
            num += number ;
            cout << "Result after adding " << number << " is : ";
        }
        void Subtract(float number)
        {
            num -= number ;
            cout << "Result after subtracting " << number << " is : ";
        }
        void Divide(float number)
        {
            if (number == 0)
            {
                num /= 1 ;
                cout << "Result after dividing 1 is : ";
            }
            else
            {
                num /= number ;
                cout << "Result after dividing " << number << " is : ";
            }
        }
        void Multiply(float number)
        {
            num *= number ;
            cout << "Result after multiplying " << number << " is : ";
        }
        void PrintResult()
        {
            cout << num << endl;
        }
        void Clear()
        {
            num = 0 ;
            cout << "Result after clear 0 is : ";
        }
};

int main()
{
    SimpleCalculator CC1;
    CC1.Add(10);
    CC1.PrintResult();
    CC1.Add(100);
    CC1.PrintResult();
    CC1.Subtract(20);
    CC1.PrintResult();
    CC1.Divide(0);
    CC1.PrintResult();
    CC1.Divide(2);
    CC1.PrintResult();
    CC1.Multiply(3);
    CC1.PrintResult();
    CC1.Clear();
    CC1.PrintResult();
    cout << "Hello world!" << endl;
    return 0;
}

