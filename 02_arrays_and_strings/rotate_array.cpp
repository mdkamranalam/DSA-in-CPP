#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Array Rotation (Rotate by k)
void rotateArray(vector<int> &arr, int k)
{
    int size = arr.size();
    k = k % size; // Handle k > n
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}