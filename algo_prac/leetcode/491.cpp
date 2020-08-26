#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  set<vector<int>> st;
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> path;
    backtrack(nums, path, 0);

    return vector<vector<int>>(st.begin(), st.end());
  }

  void backtrack(const vector<int> &nums, vector<int> &path, int idx) {
    if (idx > nums.size())
      return;
    if (path.size() >= 2) {
      st.insert(path);
    }
    for (int i = idx; i < nums.size(); i++) {
      if (path.empty() || nums[i] >= path.back()) {
        path.push_back(nums[i]);
        backtrack(nums, path, i + 1);
        path.pop_back();
      }
    }
  }
};

int main() {
  Solution solution;
  vector<int> nums = {4, 6, 7, 7};
  vector<vector<int>> ret = solution.findSubsequences(nums);
  for (auto vec : ret) {
    for (auto ele : vec) {
      cout << ele << " ";
    }
    cout << endl;
  }

  return 0;
}