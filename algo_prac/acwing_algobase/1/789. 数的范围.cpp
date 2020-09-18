#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (q--) {
        int le = 0, ri = n - 1, x;
        cin >> x;
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (arr[mid] >= x) ri = mid;
            else le = mid + 1;
        }
        if (arr[le] != x) {
            cout << "-1 -1\n";
            continue;
        }
        cout << le << " ";
        le = 0, ri = n - 1;
        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            if (arr[mid] > x) ri = mid - 1;
            else le = mid;
        }
        cout << le << "\n";
    }
}