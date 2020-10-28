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
        int n = nums.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[0][i] = i == 0 ? (nums[i]) : (nums[i] + dp[0][i - 1]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                int sum = nums[j];
                for (int k = j - 1; k >= 0; k--) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum));
                    sum += nums[k];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
