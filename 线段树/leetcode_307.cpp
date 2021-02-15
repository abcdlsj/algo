#include <bits/stdc++.h>
using namespace  std;

class NumArray {
public:
    vector<int> t;
    int n = 0;
    NumArray(vector<int>& nums) {
        n = nums.size();
        t = vector<int> (n * 2, 0);
        for (int i = n, j = 0; i < 2 * n; i++, j++) t[i] = nums[j];
        for (int j = n - 1; j > 0; j--) t[j] = t[j * 2] + t[j * 2 + 1];
    }
    
    void update(int index, int val) {
        int idx = index + n, le, ri;
        t[idx] = val;
        while (idx) {
            le = idx, ri = idx;
            if (idx % 2) le = idx - 1;
            else ri = idx + 1;
            idx /= 2;
            t[idx] = t[le] + t[ri];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += n, right += n;
        while (left <= right) {
            if (left % 2) {
                sum += t[left];
                left++;
            }
            if (right % 2 == 0) {
                sum += t[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */