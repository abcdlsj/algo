#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt;
vector<int> fa, ra, di;
int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return ;
    ra[y] += ra[x], fa[x] = y, di[x] = 1;
    cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        int x, y;
        vector<vector<int>> edges(n);
        for(int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int q, m; cin >> q;
        vector<int> monitors(q);
        for (int i = 0; i < q; i++) cin >> monitors[i];
    }
}