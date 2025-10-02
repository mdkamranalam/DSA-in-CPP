#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size)
{
    bool isSwapped;

    for (int i = 0; i < size - 1; i++)
    {
        isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {7, 12, 9, 11, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "---------- BUBBLE SORT ----------" << endl;
    cout << "Original array: ";
    printArray(arr, size);

    bubbleSort(arr, size);
    cout << "\nAfter bubble sort: ";
    printArray(arr, size);
    cout << "---------------------------------" << endl;

    return 0;
}