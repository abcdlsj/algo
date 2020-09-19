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
        // int n = nums.size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // for (int i = 0; i < n; i++) {
        //     dp[0][i] = i == 0 ? (nums[i]) : (nums[i] + dp[0][i - 1]);
        // }

        // for (int i = 1; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         dp[i][j] = INT_MAX;
        //         int sum = nums[j];
        //         for (int k = j - 1; k >= 0; k--) {
        //             dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum));
        //             sum += nums[k];
        //         }
        //     }
        // }

        // return dp[m - 1][n - 1];
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
        int count = 1, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur > target) {
                count++;
                cur = nums[i];
                if (count > m) return false;
            }
        }
        return true;
    }
    
    bool check1(vector<int>& nums, int target, int m) {
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

int main() {
    Solution solution;
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    cout << solution.splitArray(nums, 2) << endl;
}