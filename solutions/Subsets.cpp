// Problem 7: Subsets
// Find all subsets of a given set of distinct integers.

#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& result) {
    if (idx == nums.size()) {
        result.push_back(current);
        return;
    }
    findSubsets(nums, idx + 1, current, result);
    current.push_back(nums[idx]);
    findSubsets(nums, idx + 1, current, result);
    current.pop_back();
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(const_cast<vector<int>&>(nums), 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}