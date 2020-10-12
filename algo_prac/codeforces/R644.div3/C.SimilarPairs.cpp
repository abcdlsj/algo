#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        // cx 偶数个数， cy 奇数个数
        int cx = 0, cy = 0, cz = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                cx++;
            else
                cy++;
        }

        if (cx % 2 == 0 && cy % 2 == 0) {
            cout << "YES" << endl;
            continue;
        } else if (cz == 0) {
            cout << "NO" << endl;
            continue;
        }

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i += 2) {
            if (arr[i - 1] + 1 == arr[i])
                cz++;
        }
    }
}