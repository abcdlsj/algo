/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums);
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + dp[i], dp[i]);
            ans = max(dp[i], ans);
        }

        return ans;
    }
};
// @lc code=end

