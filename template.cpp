#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100005
typedef long long ll;
typedef pair<int, int> P;

const int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1},
          ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

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

int main() {

}