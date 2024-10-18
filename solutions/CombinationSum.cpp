// Problem 16: Combination Sum
// Given an array of distinct integers and a target, return all unique combinations that sum to target.

#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int idx) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = idx; i < candidates.size(); ++i) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], current, result, i);
            current.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(candidates, target, current, result, 0);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}