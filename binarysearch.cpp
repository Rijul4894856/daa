#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> unsortedArray = {34, 7, 23, 32, 5, 62};
    int target = 23;

    sort(unsortedArray.begin(), unsortedArray.end());
    cout << "Sorted Array: ";
    for (int num : unsortedArray)
        cout << num << " ";
    cout << endl;

    int result = binarySearch(unsortedArray, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result << " in the sorted array." << endl;
    else
        cout << "Element " << target << " not found." << endl;

    return 0;
}
