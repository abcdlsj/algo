#include <bits/stdc++.h>
#include "../utils/print.h"
using namespace std;

// LCS
int lcs(string s, string t, int m, int n) {
  if (m == 0 || n == 0) {
    return 0;
  }
  if (s[m - 1] == t[n - 1]) {
    return 1 + lcs(s, t, m - 1, n - 1);
  }
  return max(lcs(s, t, m, n - 1), lcs(s, t, m - 1, n));
}

// dp
int lcs_dp(string s, string t) {
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) dp[i][j] = 0;
      else if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  print_vec(dp);
  return dp[m][n];
}
int main() {
  string a = "AGGTAB", b = "GXTXAYB";
  cout << a << " " << b << "\n" << lcs(a, b, a.size(), b.size()) << "\n";

  cout << a << " " << b << "\n" << lcs_dp(a, b) << "\n";

  return 0;
}
