#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    vector<int> cnt;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < 1) {
            ans += (1 - x);
            if (map[1] == 1) cnt.push_back(1);
            else map[1] = 1;
        } else if (x > n) {
            ans += (x - n);
            if (map[n] == 1) cnt.push_back(n);
            else map[n] = 1;
        } else {
            if (map[x] == 1) {
                cnt.push_back(x);
            } else {
                map[x] = 1;
            }
        }
    }
    // sort(nums.begin(), nums.end());

    for (auto& e : cnt) {
        int le = e, ri = e;
        int a = INT_MAX, b = INT_MAX;
        while (map[le] != 0 && le >= 1) {
            le--;
            a = min(a, e - le);
        }
        while (map[ri] != 0 && ri <= n) {
            ri++;
            b = min(b, ri - e);
        }
        if (a < b) {
            map[le] = 1;
            ans += a;
        } else {
            map[ri] = 1;
            ans += b;
        }
    }

    cout << ans << endl;
}