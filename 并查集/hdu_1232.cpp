#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> father;
vector<int> ranks;
int findset(int x) {
    if (x != father[x]) {
        father[x] = findset(father[x]);
    }
    return father[x];
}
void unionset(int a, int b) {
    int x = findset(a), y = findset(b);
    if (x == y)
        return;
    if (ranks[x] > ranks[y]) {
        swap(x, y);
    }
    father[x] = y;
    ranks[y] += ranks[x];
    cnt--;
}

int main() {
    int N, M;
    while (cin >> N >> M && N != 0) {
        father.resize(N + 1);
        ranks.resize(N + 1, 1);
        cnt = N;
        for (int i = 0; i <= N; i++)
            father[i] = i;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            unionset(a, b);
        }

        cout << cnt - 1 << endl;
    }
}