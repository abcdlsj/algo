#include <bits/stdc++.h>
using namespace std;

void update(int l, int r, int c, vector<int> &cnt) {
    cnt[l] += c;
    cnt[r + 1] -= c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[i] += arr[i - 1];
        cnt[i + 1] -= arr[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        update(l, r, c, cnt);
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        cout << cnt[i] << " ";
    }
}