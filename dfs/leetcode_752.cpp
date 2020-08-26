#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    int count = 0;
    if (target == "0000")
      return 0;
    vector<int> op = {-1, 1};
    set<string> deadset(deadends.begin(), deadends.end());
    if (deadset.count("0000"))
      return -1;
    queue<string> que;
    que.push("0000");
    if (target == "0000")
      return 0;
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        string ss = que.front();
        que.pop();
        if (ss == target)
          return count;
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 2; j++) {
            string tmp = ss;
            if (tmp[i] == '0' && op[j] == -1) {
              tmp[i] = '9';
            } else if (tmp[i] == '9' && op[j] == 1) {
              tmp[i] = '0';
            } else {
              tmp[i] += op[j];
            }
            if (deadset.count(tmp)) {
              continue;
            } else {
              que.push(tmp);
              deadset.insert(tmp);
            }
          }
        }
      }
      count++;
    }
    return -1;
  }
};

int main() {
  Solution solution;
  // ...
}