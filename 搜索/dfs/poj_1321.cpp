#include <iostream>
using namespace std;

int rows[10], n, k, ans;
char board[10][10];

void dfs(int step, int x) {
    if (x == k) {
        ans++;
        return ;
    }
    if (step > n) {
        return ;
    }
    for (int i = 0; i < n; ++i) {
        if (board[step][i] == '#' && rows[i] == false) {
            rows[i] = true;
            dfs(step + 1, x + 1);
            rows[i] = false;
        }
    }
    dfs(step + 1, x);
}

int main() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1) {
            break;
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}