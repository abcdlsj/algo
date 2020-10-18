#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int le, int ri, int root) {
    if (le == ri) return 0; 
    int res = 0;
    int lm = min_element(nums.begin() + le, nums.begin() + root - 1) - nums.begin();
    int rm = min_element(nums.begin() + root + 1, nums.begin() + ri) - nums.begin();
    res += nums[root] * (nums[lm] + nums[rm]) + solve(nums, le, root - 1, lm) + solve(nums, root + 1, ri, rm);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> nums;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        ans = min(solve(nums, 0, n - 1, i), ans);
    }
    cout << ans << endl;
}