#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &arr, int le, int ri) {
    arr[le] += 1;
    arr[ri + 1] -= 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N && N != 0) {
        vector<int> arr(N + 2, 0);
        int a, b;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            update(arr, a, b);
        }
        for (int i = 1; i <= N; i++) {
            arr[i] += arr[i - 1];
        }
        for (int i = 1; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[N] << "\n";
    }
}