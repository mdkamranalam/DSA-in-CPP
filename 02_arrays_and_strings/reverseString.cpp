#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        swap(str[left++], str[right--]);
    }
}