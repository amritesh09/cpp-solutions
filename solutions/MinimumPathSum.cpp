// Problem 6: Minimum Path Sum
// Find the minimum path sum in a grid, starting from the top left and moving only down or right.

#include <iostream>
#include <vector>
using namespace std;

int minPathSum(const vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    
    for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + grid[0][j];
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum Path Sum: " << minPathSum(grid) << endl;
    return 0;
}