// Problem 14: Find Peak Element
// A peak element is an element that is strictly greater than its neighbors. Find a peak element in an array.

#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << "Peak Element Index: " << findPeakElement(nums) << endl;
    return 0;
}