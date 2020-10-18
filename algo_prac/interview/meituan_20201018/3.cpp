#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> table(n);
        vector<vector<int>> cnt(2);
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            table[i] = s[i] - '0';
            if (table[i] != 2) cnt[table[i]].push_back(i + 1);
        }
        queue<int> que;
        int m; cin >> m;
        cin >> s;
        for (int i = 0; i < m; i++) {
            char in = s[i];
            if (in == 'M') {
                if (!cnt[1].empty()) {
                    cout << cnt[1].front() << endl;
                    cnt[1].erase(cnt[1].begin());
                } else {
                    cout << cnt[0].front() << endl;
                    int a = cnt[0].front();
                    cnt[0].erase(cnt[0].begin());
                    auto iter = upper_bound(cnt[1].begin(), cnt[1].end(), a);
                    cnt[1].insert(iter, a);
                }
            } else {
                if (!cnt[0].empty()) {
                    cout << cnt[0].front() << endl;
                    int a = cnt[0].front();
                    cnt[0].erase(cnt[0].begin());
                    auto iter = upper_bound(cnt[1].begin(), cnt[1].end(), a);
                    cnt[1].insert(iter, a);
                } else {
                    cout << cnt[1].front() << endl;
                    cnt[1].erase(cnt[1].begin());
                }
            }
        }
    }
}