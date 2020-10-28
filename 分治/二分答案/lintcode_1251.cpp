#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        // write your code here
        int sum = accumulate(nums.begin(), nums.end(), 0), max_e = *max_element(nums.begin(), nums.end());
        int ri = sum, le = max_e;
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
    bool check(vector<int>& nums, int target, int m) {
        int count = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur == target) {
                count++;
                cur = 0;
                continue;
            }
            if (cur > target) {
                count++;
                cur = nums[i];
            }
        }
        if (cur > 0) {
            count++;
        }
        return count <= m;
    }
};