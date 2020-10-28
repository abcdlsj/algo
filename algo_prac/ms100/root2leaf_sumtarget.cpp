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
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return ret;
        vector<int> path;
        helper(root, path, sum);

        return ret;
    }

    void helper(TreeNode *root, vector<int> &path, int target) {
        if (root == nullptr)
            return;
        path.push_back(root->val);

        if (root->val == target && !root->left && !root->right) {
            ret.push_back(path);
        }
        helper(root->left, path, target - root->val);
        helper(root->right, path, target - root->val);
        path.pop_back();
    }
};