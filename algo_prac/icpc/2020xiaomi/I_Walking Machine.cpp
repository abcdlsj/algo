#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> b(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                b[i][j] = s[j];
            }
        }
    }
}