#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    ll ans = -1;

    vector<vector<ll>> m(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
            if (i >= 1 && j >= 1) {
                m[i][j] += m[i - 1][j - 1];
            }
            ans = max(ans, m[i][j]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

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