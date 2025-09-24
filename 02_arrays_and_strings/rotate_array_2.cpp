#include <iostream>
#include <vector>
#include "rotate_array.cpp"
using namespace std;

void rotate(vector<int> &arr, int k) {
    int size = arr.size();
    k = k % size;
    rotateArray(arr, k);
}