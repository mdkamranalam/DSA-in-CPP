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

void selectionSortDescending(int *arr, int size)
{
    for (int i = 0; i < size - 2; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {11, 12, 22, 25, 64};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "---------- SELECTION SORT ----------" << endl;
    cout << "Original array: ";
    printArray(arr, size);
    selectionSortDescending(arr, size);
    cout << "\nAfter selection sort: ";
    printArray(arr, size);
    cout << "------------------------------------" << endl;

    return 0;
}