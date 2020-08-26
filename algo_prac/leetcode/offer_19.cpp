#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    return matchHelper(s.c_str(), p.c_str(), 0, 0);
  }

  bool matchHelper(const string &s, const string &p, int i, int j) {
    if (i == s.size() && j == p.size())
      return true;
    if (i != s.size() && j == p.size())
      return false;
    bool res = i != s.size() && (p[j] == s[i] || p[j] == '.');
    if (p[j + 1] != '*') {
      return res && matchHelper(s, p, i + 1, j + 1);
    } else {
      return matchHelper(s, p, i, j + 2) ||
             (res && matchHelper(s, p, i + 1, j));
    }
  }
  bool ismatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 1; j <= p.size(); j++) {
        if (p[j - 1] != '*') {
          if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
            dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 2];
          if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        }
      }
    }
    return dp[s.size()][p.size()];
  }
};

int main() {
  Solution solution;
  if (solution.ismatch("aa", "a*")) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}