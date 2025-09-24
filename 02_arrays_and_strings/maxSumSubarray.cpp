#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int> &arr, int k)
{
    int size = arr.size();
    if (size < k)
        return -1;

    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < size; i++)
    {
        windowSum = windowSum + arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}