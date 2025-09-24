#include <iostream>
#include <vector>
#include <string>

#include "rotate_array.cpp"
#include "reverseString.cpp"
#include "maxSumSubarray.cpp"
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // Array Rotation
    cout << "---------- Array Rotation ----------" << endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int d = 2;
    cout << "Original Array: ";
    printArray(arr1);
    rotateArray(arr1, d);
    cout << "Rotated Array: ";
    printArray(arr1);
    cout << endl; // New Line

    // Reverse String
    cout << "---------- Reverse String ----------" << endl;
    string str = "Hello";
    cout << "Original string: " << str << endl;
    reverseString(str);
    cout << "Reverse string: " << str << endl;
    cout << endl; // New Line

    // Sliding Window (Find max sum subarray of size k)
    cout << "---------- Sliding Window (Find max sum subarray of size k) ----------" << endl;
    // vector<int> arr2 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k = 4;
    cout << "Max sum of subarray of size " << k << ": " << maxSumSubarray(arr2, k) << endl;
    cout << endl; // New Line

    return 0;
}