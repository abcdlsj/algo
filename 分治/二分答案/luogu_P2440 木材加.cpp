#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int len, int n) {
    int cur = 0;
    for (int i = 0; i < arr.size(); i++) {
        cur += arr[i] / len;
        if (cur >= n)
            return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int le = 0, ri = *max_element(arr.begin(), arr.end());

    while (le < ri) {
        int mid = le + (ri - le + 1) / 2;
        if (check(arr, mid, K)) {
            le = mid;
        } else {
            ri = mid - 1;
        }
    }

    cout << le << "\n";
}