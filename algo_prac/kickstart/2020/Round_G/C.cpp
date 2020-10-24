#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n, m; // [1, m]
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll ans = LLONG_MAX;
    for (int i = 1; i <= m; i++) {
        ll cur = 0;
        for (auto& e : arr) {
            if (e < i) {
                cur += min(i - e, abs(e + m - i));
            } else {
                cur += min(e - i, abs(m - e + i));
            }
        }
        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}