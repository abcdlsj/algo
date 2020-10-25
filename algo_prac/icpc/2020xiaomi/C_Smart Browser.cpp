#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int get(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return n + n - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while (cin >> s) {
        int cur = 0;
        ll ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'v') {
                ans += get(cur);
                cur = 0;
            } else {
                cur++;
            }
        }
        ans += get(cur);
        cout << ans << endl;
    }
}