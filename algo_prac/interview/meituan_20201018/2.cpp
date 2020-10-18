#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, int m, int x, int y) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > m) cnt++;
    }

    int cnt2 = nums.size() - cnt;
    if (cnt >= x && cnt <= y && cnt2 >= x && cnt2 <= y) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int le = 0, max_e = *max_element(nums.begin(), nums.end()), ri = max_e;
    while (le < ri) {
        int mid = le + (ri - le) / 2;
        if (check(nums, mid, x, y)) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }

    if (le == max_e) cout << -1 << endl;
    else cout << le << endl;
}