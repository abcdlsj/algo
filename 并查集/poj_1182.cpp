#include <iostream>
#define MAX_N 150005
using namespace std;

int fa[MAX_N], ra[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        ra[i] = 1;
    }
}
int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (ra[x] > ra[y]) swap(x, y);
    ra[y] += ra[x], fa[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int N, K;

void solve() {
	init(3 * N);
    int ans = 0;
	for (int i = 0; i < K; i++) {
        //
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        x = x - 1, y = y - 1;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            ans++;
            continue;
        }
        if (t == 1) {
            if (same(x, y + N) || same(x, y + 2 * N)) {
                ans++;
                continue;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        } else {
            if (x == y) {
                ans++;
                continue;
            }
            if (same(x, y + 2 * N) || same(x, y)) {
                ans++;
                continue;
            } else {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
	}

    printf("%d\n", ans);
}

int main () {
    scanf("%d%d", &N, &K);
    solve();
}
