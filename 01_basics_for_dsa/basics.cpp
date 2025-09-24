#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Array and Vector Operations
void arrayAndVector()
{
    // Basic Array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // STL Vector
    vector<int> vec = {10, 20, 30};
    vec.push_back(100); // Add element
    cout << "Vector elements: ";
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Pointers
void pointer()
{
    int x = 10;
    int *ptr = &x;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl;
    *ptr = 20; // Modify via pointer
    cout << "New value of x: " << x << endl;
}

// Pairs
void pairs()
{
    pair<int, string> p = {1, "apple"};
    cout << "Pairs: (" << p.first << ", " << p.second << ")" << endl;
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}};
    vp.push_back({5, 6});
    cout << "Vector of pairs: ";
    for (auto &pr : vp)
    {
        cout << "(" << pr.first << ", " << pr.second << ") ";
    }
    cout << endl;
}

// LeetCode: Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result = {i, j};
                break;
            }
        }
    }
    return result;
}

// Main Function
int main()
{
    cout << "---------- Array and Vector ----------" << endl;
    arrayAndVector();
    cout << "---------- Pointers ----------" << endl;
    pointer();
    cout << "---------- Pairs ----------" << endl;
    pairs();
    cout << endl;
    cout << "---------- LeetCode: Two Sum ----------" << endl;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> indices = twoSum(nums, target);
    cout << "Two Sum indices: [" << indices[0] << ", " << indices[1] << "]" << endl;

    return 0;
}