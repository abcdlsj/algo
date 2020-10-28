#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int ans;

void dfs(vector<vector<char>>& b, int i, int j) {
    if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] == '.') return ;
    b[i][j] = '.';
    for (int k = 0; k < 8; k++) {
        dfs(b, i + ddx[k], j + ddy[k]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    while (cin >> N >> M) {
        ans = 0;
        vector<vector<char>> board(N, vector<char>(M));
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            for (int j = 0; j < M; j++) {
                board[i][j] = s[j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'W') {
                    ans++;
                    dfs(board, i, j);
                }
            }
        }

        cout << ans << endl;
    }
}