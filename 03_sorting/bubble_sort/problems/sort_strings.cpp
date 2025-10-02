#include <iostream>
#include <string>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

string bubbleSortString(string str, int size)
{
    int swapCount = 0;
    bool isSwapped;

    for (int i = 0; i < size - 1; i++)
    {
        isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                swap(str[j], str[j + 1]);
                isSwapped = true;
                swapCount++;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
    cout << "\nTotal swap count: " << swapCount << endl;
    return str;
}

int main()
{
    string str = "hello";
    int size = str.length();

    cout << "---------- SORTING STRING USING BUBBLE SORT ----------" << endl;
    cout << "Original string: " << str << endl;
    string newStr = bubbleSortString(str, size);
    cout << "\nSorted string: " << newStr << endl;
    cout << "------------------------------------------------------" << endl;

    return 0;
}