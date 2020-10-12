#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        vector<pair<int, int>> pos(n);
        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            pos[i].first = x;
            pos[i].second = y;
        }
    }
}