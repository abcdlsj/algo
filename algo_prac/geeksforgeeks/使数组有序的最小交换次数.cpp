#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
int minSwaps(vector<int> &arr, int n) {
  vector<pair<int, int>> pos(n);
  vector<int> vis(n, false);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    pos[i].first = arr[i];
    pos[i].second = i;
  }

  sort(pos.begin(), pos.end());
  for (int i = 0; i < n; i++) {
    if (vis[i] || pos[i].second == i) {
      continue;
    }
    int j = i, loops = 0;
    while (!vis[j]) {
      vis[j] = true;
      j = pos[j].second;
      loops++;
    }
    if (loops > 0) {
      ans += loops - 1;
    }
  }


  return ans;
}

int main() {
  vector<int> arr = {1, 5, 4, 3, 2};
  cout << minSwaps(arr, arr.size());
  return 0;
}