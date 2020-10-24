#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    while (cin >> n) {
        vector<ll> dp;
        for (int i = 0; i < n; i++) {
            cin >> x;
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }

        // for (auto& e : dp) cout << e << " "; cout << endl;
        cout << dp.size() << endl;
    }
}