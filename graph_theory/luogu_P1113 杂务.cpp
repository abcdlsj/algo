#include <bits/stdc++.h>
using namespace std;

// TODO
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> costs(n + 1, -1);
    vector<int> nopre;
    vector<vector<int>> G(n + 1);

    for (int i = 0; i < n; i++) {
        int idx, time, x;
        cin >> idx >> time;
        costs[idx] = time;
        while (cin >> x && x != 0) {
            G[x].push_back(idx);
        }
    }
    int ans = *max_element(costs.begin(), costs.end());
    int time = 0;

    for (int i = 0; i < )
}