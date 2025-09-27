#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    cout << "*---------- RECURSIVE FIBONACCI NUMBER ----------*" << endl;
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int result = fibonacci(n);

    cout << "Fibonacci Numbers from 0 to " << n << ": " << result << endl;
    cout << "*------------------------------------------------*" << endl;

    return 0;
}