#include <bits/stdc++.h>
using namespace std;

/*
题目背景
一年一度的“跳石头”比赛又要开始了!
题目描述
这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。
在起点和终点之间，有 NN
块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。
为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。
由于预算限制，组委会至多从起点和终点之间移走 M
块岩石（不能移走起点和终点的岩石）。 输出格式 一个整数，即最短跳跃距离的最大值。
*/
bool check(vector<int> &pos, int dis, int m) {
    int pre = pos[0];
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - pre >= dis) {
            pre = pos[i];
        } else {
            m--;
        }
        if (m < 0)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, N, M;
    while (cin >> L >> N >> M) {
        vector<int> pos;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            pos.push_back(x);
        }
        pos.insert(pos.begin(), 0);
        pos.push_back(L);
        int le = 0, ri = pos.back();
        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            if (check(pos, mid, M)) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }
        cout << le << endl;
    }
}