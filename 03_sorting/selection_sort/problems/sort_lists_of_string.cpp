#include <iostream>
#include <string>
using namespace std;

void printString(string *str)
{
    int size = str->length();
    for (int i = 0; i < size; i++)
        cout << str[i] << " ";
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSortString(string *str, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (str[j] < str[minIndex])
                minIndex = j;
        }
        swap(str[i], str[minIndex]);
    }
}

int main()
{
    string str[] = {"banana", "apple", "cherry", "date"};
    int size = sizeof(str) / sizeof(str[0]);
    cout << "---------- Sort a list of strings alphabetically ----------" << endl;
    printString(str);
    selectionSortString(str, size);
    printString(str);
    cout << "-----------------------------------------------------------" << endl;

    return 0;
}