#include <iostream>
#include <string>

using namespace std;

int sumOfEvenDigits(int numericalValue)
{
    int sumEven = 0;
    cout << "Even digits: ";
    while (numericalValue > 0)
    {
        int digit = numericalValue % 10;
        if (digit % 2 == 0)
        {
            cout << digit << " ";
            sumEven += digit;
        }
        numericalValue /= 10;
    }
    cout << endl;
    return sumEven;
}

int main()
{
    string vuStudentID = "BC230400215";

    cout << "VU Student ID: " << vuStudentID << endl;

    string numericalPart = vuStudentID.substr(2);
    cout << "Numerical part of VU Student ID: " << numericalPart << endl;

    int numericalValue = stoi(numericalPart);

    int sumEven = sumOfEvenDigits(numericalValue);

    cout << "Sum of even digits: " << sumEven << endl;

    return 0;
}
