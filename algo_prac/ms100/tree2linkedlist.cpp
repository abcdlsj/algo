#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
