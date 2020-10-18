#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> fa;
vector<int> ra;

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
    fa[x] = fa[y];
    cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // TODO
}