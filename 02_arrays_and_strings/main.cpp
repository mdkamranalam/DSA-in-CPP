#include <iostream>
#include <vector>

#include "rotate_array.cpp"
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    // Array Rotation
    cout << "---------- Array Rotation ----------" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    cout << "Original Array: ";
    printArray(arr);
    rotateArray(arr, k);
    cout << "Rotated Array: ";
    printArray(arr);

    return 0;
}