#include <bits/stdc++.h>
using namespace std;

const string a = "KICK", b = "START";
void solve() {
    string s;
    cin >> s;
    int ans = 0;

    vector<int> idx1, idx2;
    int p = 0;
    while ((p = s.find(a, p)) != string::npos) {
        idx1.push_back(p);
        p++;
    }
    p = 0;
    while ((p = s.find(b, p)) != string::npos) {
        idx2.push_back(p);
        p++;
    }

    for (int i = 0; i < idx1.size(); i++) {
        int k = idx1[i] + 4;
        for (int j = 0; j < idx2.size(); j++) {
            int cur = idx2[j];
            if (cur >= k) {
                ans += idx2.size() - j;
                break;
            }
        }
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}