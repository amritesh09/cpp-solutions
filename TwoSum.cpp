// Problem 1: Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return { numMap[complement], i };
        }
        numMap[nums[i]] = i;
    }
    return {}; // No solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}