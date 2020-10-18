#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n; cin >> n;
        string res, s;
        int m = -1;
        getline(cin, s);

        vector<int> cnt(26, 0);
        while (n--) {
            getline(cin, s);
            int si = 0;
            for (auto &e : s) {
                if (cnt[e - 'a'] == 0) {
                    si++;
                    cnt[e - 'a']++;
                }
            }
            cnt.resize(26, 0);
            if (si > m) {
                m = max(m, si);
                res = s;
            }
        }

        cout << "Case #" << i << ": " << res << endl;
    }

    fclose(stdin);
    fclose(stdout);
}
