#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    vector<int> costs(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> G(n + 1);
    vector<int> ret(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b;
        costs[i] = b;
        while (cin >> c && c) {
            G[c].push_back(i);
            indegree[i]++;
        }
    }
    
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            que.push(i);
            ret[i] = costs[i];
        }
    }

    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (auto& e : G[cur]) {
            indegree[e]--;
            if (indegree[e] == 0) {
                que.push(e);
            }
            ret[e] = max(ret[e], ret[cur] + costs[e]);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, ret[i]);
    }

    cout << ans << endl;
}