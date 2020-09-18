#include "../utils/utils_tree.h"
using namespace std;

// class Solution {
// public:
//     vector<int> ret;
//     vector<int> boundaryOfBinaryTree(TreeNode* root) {
//         if (root == nullptr) return ret;
//         if (root->left || root->right) ret.push_back(root->val);
//         add_left(root->left);
//         add_leaf(root);
//         add_right(root->right);
//         return ret;
//     }
//     void add_left(TreeNode* node) {
//         if (!node || (!node->left && !node->right)) return ;
//         ret.push_back(node->val);
//         if (node->left) add_left(node->left);
//         else add_left(node->right);
//     }
//     void add_right(TreeNode* node) {
//         if (!node || (!node->right && !node->right)) return ;
//         if (node->right) add_right(node->right);
//         else add_right(node->left);
//         ret.push_back(node->val);
//     }
//     void add_leaf(TreeNode* node) {
//         if (!node) return ;
//         if (!node->left && !node->right) ret.push_back(node->val);
//         add_left(node->left);
//         add_right(node->right);
//     }

// };
class Solution {
   public:
    vector<int> ret;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return ret;
        ret.push_back(root->val);
        helper(root->left, true, false);
        helper(root->right, false, true);
        return ret;
    }
    void helper(TreeNode* node, bool is_left, bool is_right) {
        if (!node) return;
            if (node && !node->left && !node->right) {
            ret.push_back(node->val);
            return;
        }
        if (is_left) ret.push_back(node->val);
        // 进入左边，如果 root->left 有的话会优先添加 left;
        helper(node->left, is_left && node->left, is_right && !node->right);
        // 进入右边，如果 root->right 有的话会优先添加 right;
        helper(node->right, is_left && !node->left, is_right && node->right);
        if (is_right) ret.push_back(node->val);
    }
};
int main() {}