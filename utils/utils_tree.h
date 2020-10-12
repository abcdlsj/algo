#include "myatoi.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
// preorder inorder postorder

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr){};
    string preSerialize(TreeNode *root) {
        // '_' 分隔，'#' 代表空
        if (root == nullptr)
            return "#_";
        string res = to_string(root->val) + "_";
        res += preSerialize(root->left);
        res += preSerialize(root->right);
        return res;
    }
    static TreeNode *dePreSerialize(string data) {
        stringstream ss(data);
        string tmp = "";
        queue<string> que;
        while (getline(ss, tmp, '_')) {
            que.push(tmp);
        }
        return dePreHelper(que);
    }
    static TreeNode *dePreHelper(queue<string> &que) {
        string cur = que.front();
        que.pop();
        if (cur == "#")
            return nullptr;
        TreeNode *root = new TreeNode(myatoi(cur));
        root->left = dePreHelper(que);
        root->right = dePreHelper(que);
        return root;
    }

    static TreeNode *deLevSerialize(string data) {
        // '#' 空，'_' 间隔，约定写满所有节点，包括空节点，包括所有空节点！！！
        stringstream ss(data);
        vector<TreeNode *> nodes;
        string tmp = "";
        while (getline(ss, tmp, '_')) {
            if (tmp == "#")
                nodes.push_back(nullptr);
            else {
                int n = myatoi(tmp);
                TreeNode *node = new TreeNode(n);
                nodes.push_back(node);
            }
        }
        for (int i = 0; i < nodes.size() / 2; i++) {
            if (nodes[i] == nullptr)
                continue;
            nodes[i]->left = nodes[i * 2 + 1];
            nodes[i]->right = nodes[i * 2 + 2];
        }

        return nodes[0];
    }

    void levelDisplay() {
        TreeNode *root = this;
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode *cur = que.front();
                que.pop();
                cout << cur->val << " ";
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }
        cout << endl;
    }

    void preDisplay() {
        TreeNode *root = this;
        stack<TreeNode *> stk;
        if (root != nullptr)
            stk.push(root);

        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            cout << cur->val << " ";
            if (cur->right)
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);
        }

        cout << endl;
    }
};
