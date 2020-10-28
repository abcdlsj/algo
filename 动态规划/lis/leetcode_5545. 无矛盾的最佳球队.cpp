#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
class Solution {
  public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        vector<pii> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = make_pair(ages[i], scores[i]);
        sort(arr.begin(), arr.end());

        vector<int> dp(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = arr[i].second;
            for (int j = 0; j < i; j++) {
                if (arr[i].second >= arr[j].second) {
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};