#include <bits/stdc++.h>
using namespace std;

void update(vector<vector<int> >& cnt, int x1, int y1, int x2, int y2) {
    cnt[x1][y1] += 1;
    cnt[x2 + 1][y1] -= 1; 
    cnt[x1][y2 + 1] -= 1;
    cnt[x2 + 1][y2 + 1] += 1;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int> > cnt(n + 5, vector<int>(n + 5, 0));
        for (int i = 0; i < m; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            update(cnt, x1, y1, x2, y2);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cnt[i][j] += cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << cnt[i][j] << " ";
            }
            cout << "\n";
        }
    }
}