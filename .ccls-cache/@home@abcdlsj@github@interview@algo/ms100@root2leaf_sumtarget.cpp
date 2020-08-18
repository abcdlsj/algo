#include "../utils_tree.h"
#include <bits/stdc++.h>
using namespace std;

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

int main() {
  Solution solution;
  TreeNode *root = TreeNode::deLevSerialize("5_4_8_11_#_13_4_7_2_#_#_#_#_5_1");
  root->levelDisplay();
  vector<vector<int>> res = solution.pathSum(root, 22);
  for (auto vec : res) {
    for (auto ele : vec) {
      cout << ele << " ";
    }
    cout << "\n";
  }
}