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

int kthSmallest(int *arr, int size, int k)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr[k - 1];
}

int main()
{
    int arr[] = {5, 9, 1, 3, 7, 2};
    int k = 1;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "---------- k-th Smallest Element using Selection Sort ----------" << endl;

    if (k <= 0 || k >= size)
    {
        cout << "Value of k should between 1 to " << size - 1 << " of the array." << endl;
    }
    else
    {
        cout << "Array: ";
        printArray(arr, size);

        int result = kthSmallest(arr, size, k);
        cout << "kth Smallest Element: " << result << endl;
    }
    cout << "----------------------------------------------------------------" << endl;

    return 0;
}