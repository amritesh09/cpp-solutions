// Problem 19: Word Search
// Given a 2D board and a word, find if the word exists in the board.

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    if (idx == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
    
    char temp = board[i][j];
    board[i][j] = '*'; // mark visited
    bool found = dfs(board, word, i + 1, j, idx + 1) ||
                 dfs(board, word, i - 1, j, idx + 1) ||
                 dfs(board, word, i, j + 1, idx + 1) ||
                 dfs(board, word, i, j - 1, idx + 1);
    board[i][j] = temp; // unmark visited
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << "Word exists: " << (exist(board, word) ? "Yes" : "No") << endl;
    return 0;
}