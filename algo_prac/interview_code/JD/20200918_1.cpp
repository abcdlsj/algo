#include <bits/stdc++.h>
using namespace std;

// 单组输入。
// 每组测试数据的输入有n+1行，n表示道具的种类。
// 第1行包含两个正整数，分别表示道具种类数n和总价值的上限p，两个数字之间用空格隔开。
// （n<=100，p<=10000）
// 第2行到第n+1行分别对应于第1种道具到第n种道具的信息，每1行包含三个正整数，两个数字之间用空格隔开，三个正整数分别表示某一种道具的数量、单个道具的价格和魅力值。
int main() {
    int n, p;
    while (cin >> n >> p) {
        vector<vector<int>> vecs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            cin >> vecs[i][0] >> vecs[i][1] >> vecs[i][2];
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(p + 1, 0));
        vector<long long> cnt(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= p; j++) {
                // a0 数量，a1 价格，a2 魅力
                int a0 = vecs[i - 1][0], a1 = vecs[i - 1][1],
                    a2 = vecs[i - 1][2];
                for (int k = 1; k <= a0; k++) {
                    if (j < k * a1) {
                        break;
                    } else {
                        dp[i][j] = max(dp[i][j], dp[i][j - (k * a1)] + k * a2);
                    }
                }
            }
        }
        cout << dp[n][p] << endl;
    }
}
