#include <iostream>
using namespace std;

int minValue(int *arr, int size) {
    int minVal = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    return minVal;
}

int main() {
    int arr[] = {7, 12, 9, 4, 11, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = minValue(arr, size);
    cout << "Lowest value in the array: " << result << endl;

    return 0;
}