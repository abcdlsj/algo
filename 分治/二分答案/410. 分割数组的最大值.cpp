#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int splitArray(vector<int> &nums, int m) {
        int sum = accumulate(nums.begin(), nums.end(), 0),
            max_e = *max_element(nums.begin(), nums.end());
        int le = max_e, ri = sum;
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (check(nums, mid, m)) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }
        return le;
    }
    bool check(vector<int> &nums, int target, int m) {
        int count = 0, cur = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur > target) {
                count++;
                cur = nums[i];
                if (count > m)
                    return false;
            }
        }
        if (cur > 0)
            count++;
        return count <= m;
    }
};