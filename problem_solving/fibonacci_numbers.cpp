#include <iostream>
using namespace std;

int fibonacci(int firstNum, int secondNum, int n)
{
    int newNum = 0;
    for (int i = 0; i < n; i++)
    {
        newNum = firstNum + secondNum;
        secondNum = firstNum;
        firstNum = newNum;
    }
    return newNum;
}

int main()
{
    cout << "*---------- FIBONACCI NUMBER ----------*" << endl;
    int n, firstNum = 0, secondNum = 1;
    cout << "Enter the number: ";
    cin >> n;

    int result = fibonacci(firstNum, secondNum, n);

    cout << "Fibonacci Numbers from 0 to " << n << ": " << result << endl;
    cout << "*--------------------------------------*" << endl;

    return 0;
}