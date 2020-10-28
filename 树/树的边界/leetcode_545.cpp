#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> ret;
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        if (!root) return ret;
        ret.push_back(root->val);
        helper(root->left, true, false);
        helper(root->right, false, true);
        return ret;
    }
    void helper(TreeNode *root, bool is_left, bool is_right) {
        if (!root) return;
        if (!root->left && !root->right) {
            ret.push_back(root->val);
            return;
        }
        if (is_left) ret.push_back(root->val);
        helper(root->left, root->left && is_left, is_right && !root->right);
        helper(root->right, !root->left && is_left, is_right && root->right);
        if (is_right) ret.push_back(root->val);
    }
};

int main() {}