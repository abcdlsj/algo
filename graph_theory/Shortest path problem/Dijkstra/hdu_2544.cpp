#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    while (cin >> N >> N) {
        if (!N && !M) break;
        vector<vector<int>> G(N + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] = min(G[a][b], c);
        }
        vector<bool> vis(N + 1, false);
        vector<int> dis(N + 1, INT_MIN);

        for (int i = 0; i < N - 1; i++) {
            int cur = -1;
            for (int j = 1; j <= N; j++) {
                if (!vis[cur] && (cur == -1 || dis[cur] < dis[j])) {
                    cur = j;
                }
            }
            vis[cur] = true;

            for (int j = 1; j <= N; j++) {
                dis[j] = min(dis[j], dis[cur] + G[cur][j]);
            }
        }

        // if (dis[N] == INT_MAX) cout << "-1" << endl;
        cout << dis[N] << endl;
    }
}