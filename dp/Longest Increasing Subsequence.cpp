#include "../utils/print.h"
#include <bits/stdc++.h>
using namespace std;

// LIS
// O(n^2)
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(dp[i], ans);
    }

    return ans;
  }
};

// O(log(n) * n)
class Solution1 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int len = nums.size();
    if (len < 2) {
      return len;
    }

    vector<int> tail;
    tail.push_back(nums[0]);
    // tail 结尾的那个索引
    int end = 0;

    for (int i = 1; i < len; ++i) {
      if (nums[i] > tail[end]) {
        tail.push_back(nums[i]);
        end++;
      } else {
        int left = 0;
        int right = end;
        while (left < right) {
          int mid = (left + right) >> 1;
          if (tail[mid] < nums[i]) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }
        tail[left] = nums[i];
      }
    }
    return end + 1;
  }
};

class Solution2 {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp;

    for (auto &ele : nums) {
      auto find = lower_bound(dp.begin(), dp.end(), ele);
      if (find == dp.end()) {
        dp.push_back(ele);
      } else {
        *find = ele;
      }
    }

    return dp.size();
  }
};

int main() {
  Solution solution;
  vector<int> arr = {4, 10, 4, 3, 8, 9};
  // cout << lis_dp(arr) << endl;
  cout << solution.lengthOfLIS(arr) << endl;
}
