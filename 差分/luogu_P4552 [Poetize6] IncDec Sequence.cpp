#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> cnt(n, 0);
        for (int i = 1; i < n; i++) {
            cnt[i] = arr[i] - arr[i - 1];
        }
        ll pos = 0, neg = 0;

        for (int i = 1; i <= n; i++) {
            // cout << cnt[i] << " ";
            if (cnt[i] > 0) {
                pos += cnt[i];
            } else {
                // cnt[i] < 0;
                neg -= cnt[i];
            }
        }
        // cout << "\n";
        cout << min(pos, neg) + abs(pos - neg) << endl;
        cout << abs(pos - neg) + 1 << endl;
    }
}