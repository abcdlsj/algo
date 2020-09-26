#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n; cin >> m >> n; 
    vector<int> arr(m);
    vector<int> grades(n);
    for (int i = 0; i < m; i++) cin >> arr[i];
    for (int j = 0; j < n; j++) cin >> grades[j];

    long long ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(arr.begin(), arr.end(), grades[i]);
        if (it == arr.begin()) {
            ans += arr[0] - grades[i];
        } else if (it == arr.end()) {
            ans += grades[i] - arr[m - 1];
        } else {
            ans += min(*it - grades[i], grades[i] - *(it - 1));
        }
    }

    cout << ans << "\n";
}