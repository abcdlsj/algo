#include <iostream>
#define MAX_N 50005
using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int cnt;
int fa[MAX_N], ra[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        ra[i] = 1;
    }
    cnt = n;
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
    cnt--;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int N, K;
int main () {
    // TODO
    while (cin >> N >> K) {

    }
}