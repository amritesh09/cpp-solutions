// Problem 2: Longest Common Subsequence
// Given two strings, find the length of their longest common subsequence.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(const string& text1, const string& text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int result = longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << result << endl;
    return 0;
}