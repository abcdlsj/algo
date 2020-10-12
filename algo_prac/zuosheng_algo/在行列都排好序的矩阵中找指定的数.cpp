#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        int k;
        cin >> k;
        vector<vector<int>> m(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> m[i][j];
            }
        }

        int row = 0, col = N - 1;
        while (row < N && col >= 0) {
            if (k == m[row][col]) {
                cout << "Yes" << endl;
                return 0;
            } else if (k > m[row][col]) {
                row++;
            } else {
                col--;
            }
        }

        cout << "No" << endl;
        return 0;
    }
}
