#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> fa;
vector<int> ra;
int cnt;

int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
        return;
    if (ra[x] > ra[y]) {
        swap(x, y);
    }
    ra[y] += ra[x];
    fa[x] = y;
    cnt--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> vx(n + 1);
    vector<int> vy(n + 1);
    fa.resize(n + 1);
    ra.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> vx[i] >> vy[i];
        fa[i] = i;
    }
    vector<vector<int>> edges(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dis = (vx[i] - vx[j]) * (vx[i] - vx[j]) +
                      (vy[i] - vy[j]) * (vy[i] - vy[j]);
            if (dis <= d * d) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    vector<bool> repair(n + 1, false);
    char o;
    while (cin >> o && o) {
        if (o == 'O') {
            int x;
            cin >> x;
            repair[x] = true;
            for (int i = 0; i < edges[x].size(); i++) {
                if (repair[edges[x][i]]) {
                    unionset(edges[x][i], x);
                }
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (find(x) == find(y)) {
                cout << "SUCCESS\n";
            } else {
                cout << "FAIL\n";
            }
        }
    }
}