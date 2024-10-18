// Problem 17: Top K Frequent Elements
// Given a non-empty array, return the k most frequent elements.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) freqMap[num]++;
    priority_queue<pair<int, int>> pq;
    for (const auto& [num, freq] : freqMap) {
        pq.push({freq, num});
    }
    vector<int> result;
    while (k-- > 0 && !pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}