#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& pos, int dis, int c) {
    int count = 1, pre = pos[0];
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - pre >= dis) {
            count++;
            pre = pos[i];
        }
        if (count >= c) {
            return true;
        }
    } 
    return false;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    while (cin >> N >> C) {
        vector<int> pos(N);
        for (int i = 0; i < N; i++) cin >> pos[i];
        sort(pos.begin(), pos.end());

        int le = 0, ri = pos.back() - pos[0];
        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            if (check(pos, mid, C)) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }

        cout << le << endl;
    }
}