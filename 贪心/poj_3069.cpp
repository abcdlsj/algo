#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1005
int N, R;
int X[MAX_N];

void solve() {
    sort(X, X + N);
    int ans = 0, i = 0;
    while (i < N) {
        int s = X[i++];
        while (i < N && X[i] <= s + R) i++;
        int p = X[i - 1];
        while (i < N && X[i] <= p + R) i++;
        ans++;        
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> R >> N) {
        if (R == N && R == -1) break;
        for (int i = 0; i < N; i++) cin >> X[i];
        solve();
    }
}