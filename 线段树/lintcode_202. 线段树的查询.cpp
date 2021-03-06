#include <bits/stdc++.h>
using namespace std;

// Definition of SegmentTreeNode

class SegmentTreeNode {
  public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
  public:
    /**
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root->start == start && root->end == end)
            return root->max;
        int mid = (root->start + root->end) / 2, leftMax = INT_MIN,
            rightMax = INT_MIN;
        if (start <= mid) {
            leftMax = query(root->left, start, min(mid, end));
        }
        if (mid < end) {
            rightMax = query(root->right, max(mid + 1, start), end);
        }

        return max(leftMax, rightMax);
    }
};