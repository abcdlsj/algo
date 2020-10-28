#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
vector<vector<int>> G(MAX);
vector<int> A(MAX, 0);

void dfs(int n, int d) {
    if (A[n])
        return;
    A[n] = d;

    for (auto &e : G[n])
        dfs(e, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
    }

    for (int i = N; i >= 1; i--)
        dfs(i, i);
    for (int i = 1; i <= N; i++)
        cout << A[i] << " ";
    cout << "\n";
}
