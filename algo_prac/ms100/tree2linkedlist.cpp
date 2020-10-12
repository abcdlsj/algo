#include "../../utils/utils_tree.h"
#include <bits/stdc++.h>
using namespace std;
TreeNode *pre, *head;

void helper(TreeNode *cur) {
    if (cur == nullptr)
        return;
    helper(cur->left);
    if (pre == nullptr)
        head = cur;
    else
        pre->right = cur;
    cur->left = pre;
    pre = cur;
    helper(cur->right);
}

TreeNode *tree2LinkedList(TreeNode *root) {
    if (root == nullptr)
        return root;
    helper(root);
    head->left = pre;
    pre->right = head;
    return head;
}

int main() {
    // TreeNode *root =
    // TreeNode::dePreSerialize("10_6_4_#_#_8_#_#_14_12_#_#_16_#_#_");
    TreeNode *root = TreeNode::deLevSerialize("10_6_14_4_8_12_16");
    root->levelDisplay();
    TreeNode *node = tree2LinkedList(root);
    int size = 7;
    while (size--) {
        cout << node->val << " ";
        node = node->right;
    }
}