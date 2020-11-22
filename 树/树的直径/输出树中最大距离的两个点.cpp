/* 输出树中最大距离的两个点.cpp ---
 *
 * Author: abcdlsj <lisongjianshuai@gmail.com>
 * Copyright © 2020, abcdlsj, all rights reserved.
 * Created: 22 November 2020
 *
 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int n) : val(n) {}
};

TreeNode *no, *le, *ri;
int max_n = 0, max_le = 0, max_ri = 0;

int get_max(TreeNode *root) {
    int le = get_max(root->left);
    int ri = get_max(root->right);

    if (max_n < (le + ri)) {
        max_n = le + ri;
        no = root;
    }

    return max(le, ri) + 1;
}

void get_max_depth(TreeNode* node, int cur, bool flag) {
    if (node == nullptr) return ;
    if (flag && cur > max_le) {
        max_le = cur;
        le = node;
    }
    if (!flag && cur > max_ri) {
        max_ri = cur;
        ri = node;
    }
    get_max_depth(node->left, cur + 1, flag);
    get_max_depth(node->right, cur + 1, flag);
}

void func(TreeNode *root) {
    get_max(root);

    get_max_depth(no->left, 0, true);
    get_max_depth(no->right, 0, false);
}
