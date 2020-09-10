#include <bits/stdc++.h>
using namespace std;

/*
Given an array, the task is to divide it into two sets S1 and S2 such that the
absolute difference between their sums is minimum.
*/

int helper(vector<int> &arr, int idx, int cur, int sumall) {
  if (idx == 0) {
    return abs((sumall - cur) - cur);
  }

  return min(helper(arr, idx - 1, cur + arr[idx - 1], sumall),
             helper(arr, idx - 1, cur, sumall));
}

int mininum_partition(vector<int> &arr) {
  return helper(arr, arr.size(), 0, accumulate(arr.begin(), arr.end(), 0));
}

// dp
int mininum_partition_dp(vector<int> &arr) {
  int sum = accumulate(arr.begin(), arr.end(), 0);
  vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1));
  for (int i = 0; i <= arr.size(); i++) {
    dp[i][0] = true;
  }
  for (int j = 0; j <= sum; j++) {
    dp[0][j] = false;
  }

  for (int i = 1; i <= arr.size(); i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < arr[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      }
    }
  }

  int diff = sum;
  for (int j = sum / 2; j >= 0; j--) {
    if (dp[arr.size()][j]) {
      diff = sum - 2 * j;
      return diff;
    }
  }

  return sum;
}

int main() {
  vector<int> arr = {1, 6, 11, 5};
  cout << mininum_partition_dp(arr) << endl;
}