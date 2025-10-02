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
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
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