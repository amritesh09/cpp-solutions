// Problem 13: Validate Binary Search Tree
// Given a binary tree, determine if it is a valid binary search tree.

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "Is valid BST: " << (isValidBST(root) ? "Yes" : "No") << endl;
    return 0;
}